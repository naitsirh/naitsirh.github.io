// creamos las constantes necesarias
const list = document.querySelector('ul');
const titleInput = document.querySelector('#title');
const bodyInput = document.querySelector('#body');
const form = document.querySelector('form');
const submitBtn = document.querySelector('form button');




// creamos una instancia de objeto db para almacenar la base de datos abierta
let db;




window.onload = function() {
	// abrimos la base de datos; la creamos si aún no existe
	// (ver onupgradeneeded a continuación)
	let request = window.indexedDB.open('notes_db', 1);



	// un controlador de error (onerror) significa que la base de datos no se abrió
	// correctamente
	request.onerror = function() {
		console.log('No se pudo abrir la base de datos');
	};



	// el controlador onsuccess indica que la base de datos se abrió correctamente
	request.onsuccess = function() {
		console.log('Base de datos abierta con éxito');

		// almacenamos el objeto de base de datos abierto en la variable db. Esto se
		// usa mucho a continuación
		db = request.result;

		// ejecutamos la función displayData() para mostrar las notas que ya están en
		// la IDB
		displayData();
	};



	// configuramos las tablas de la base de datos si esto aún no se ha hecho 
	request.onupgradeneeded = function(e) {
		// tomamos una referencia a la base de datos abierta
		let db = e.target.result;

		// creamos un objectStore para almacenar nuestras notas (básicamente como una
		// sola tabla) incluyendo una clae de incremento automático
		let objectStore = db.createObjectStore('notes_os', { keyPath: 'id',	autoIncrement: true });

		// definimos qué elementos de datos contendrá el objectStore
		objectStore.createIndex('title', 'title', { unique: false });
		objectStore.createIndex('body', 'body', { unique: false });

		console.log('Configuración de la base de datos completa');
	};



	// creamos un controlador onsubmit para que cuando se envíe el formulario se
	// ejecute la función addData()
	form.onsubmit = addData;



	// definimos la función addData()
	function addData(e) {
		// evitamos el comportamiento predeterminado: no queremos que el formulario
		// se envíe de la forma convencional
		e.preventDefault();

		// tomamos los valores ingresados en los campos del formulario y los almacenamos
		// en un objeto listo para ser insertado en la base de datos
		let newItem = { title: titleInput.value, body: bodyInput.value };

		// abrimos una transacción de base de datos de lectura/escritura, lista para
		// agregar los datos
		let transaction = db.transaction(['notes_os'], 'readwrite');

		// llamamos a un almacén de objetos que ya se ha agregado a la base de datos
		let objectStore = transaction.objectStore('notes_os');

		// hacemos un solicitud para agregar nuestro objeto newItem al almacén de
		// objetos
		let request = objectStore.add(newItem);
		request.onsuccess = function() {
			// limpiamos el formulario listo para agregar la siguiente entrada
			titleInput.value = '';
			bodyInput.value = '';
		};

		// informamos sobre el éxito de la transacción completada, cuando todo esté
		// hecho
		transaction.oncomplete = function() {
			console.log('Transacción completada: modificación de la base de datos finalizada');

			// actualizamos la visualización de datos para mostrar el elemento recién
			// agregado, ejecutando displayData() nuevamente
			displayData();		
		};

		transaction.onerror = function() {
			console.log('Transacción no abierta debido a error');
		};
	};



	// definimos la función displayData()
	function displayData() {
		// aquí vaciamos el contenido del elemento de la lista cada vez que se actualiza
		// la panatalla. Si no hacemos esto, obtendremos duplicados en la lista cada
		// vez que se agregue una nueva nota
		while (list.firstChild) {
			list.removeChild(list.firstChild);
		};

		// abrimos el almacén de objetos y luego obtenemos un cursor, que recorre todos
		// los diferentes elementos de datos en el almacén
		let objectStore = db.transaction('notes_os').objectStore('notes_os');
		objectStore.openCursor().onsuccess = function(e) {
			// obtenemos una referencia al cursor
			let cursor = e.target.result;

			// si todavía hay otro elemento de datos para iterar, seguimos ejecutando
			// este código
			if (cursor) {
				// creamos un elemento de lista, h3 y 'p' para poner cada elemento de datos
				// dentro al mostrarlo
				// estructuramos el fragmento HTML y lo anexamos dentro de la lista
				const listItem = document.createElement('li');
				const h3 = document.createElement('h3');
				const para = document.createElement('p');

				listItem.appendChild(h3);
				listItem.appendChild(para);
				list.appendChild(listItem);

				// colocamos los datos del cursor dentro de h3 y 'para'
				h3.textContent = cursor.value.title;
				para.textContent = cursor.value.body;

				// almacenamos el ID del elemento de datos dentro de un atributo en listItem,
				// para que sepamos a qué elemento corresponde. Esto será útil más adelante
				// cuando queramos eliminar elementos
				listItem.setAttribute('data-note-id', cursor.value.id);

				// creamos un botón y lo colocamos dentro de cada listItem
				const deleteBtn = document.createElement('button');
				listItem.appendChild(deleteBtn);
				deleteBtn.textContent = 'Borrar';

				// establecemos un controlador de eventos para que cuando se hace clic 
				// en el botón, se ejecute la función deleteItem()
				deleteBtn.onclick = deleteItem;

				// iteramos al siguiente elemento del cursor
				cursor.continue();
			} else {
				// nuevamente, si el elemento de la lista está vacío, mostramos el mensaje
				// 'No hay notas almacenadas'
				if (!list.firstChild) {
					const listItem = document.createElement('li');
					listItem.textContent = 'No hay notas almacenadas';
					list.appendChild(listItem);
				}

				// si no hay más elementos de cursor para iterar, lo desplegamos
				console.log('Se muestran todas las notas');
			}
		};
	};



	// definimos la función deleteItem()
	function deleteItem(e) {
		// recuperamos el nombre de la tarea que queremos eliminar. Necesitamos
		// convertirla en un número antes de intentarla usar con IDB; las claves de
		// valor IDB son sensitivas
		let noteId = Number(e.target.parentNode.getAttribute('data-note-id'));

		// abrimos una transacción de base de datos y eliminamos la tarea, encntrándola
		// usando la identificación que obtuvimos arriba
		let transaction = db.transaction(['notes_os'], 'readwrite');
		let objectStore = transaction.objectStore('notes_os');
		let request = objectStore.delete(noteId);

		// informamos que el elemento de datos ha sido eliminado
		transaction.oncomplete = function() {
			// eliminamos el padre del botón, que es el elemento de la lista, por lo 
			// que ya no se muestra
			e.target.parentNode.parentNode.removeChild(e.target.parentNode);
			console.log('Nota ' + noteId + ' eliminada');

			// nuevamente, si el elemento de la lista está vacío, mostramos el mensaje
			// 'No hay notas almacenadas'
			if (!list.firstChild) {
				let listItem = document.createElement('li');
				listItem.textContent = 'No hay notas almacenadas';
				list.appendChild(listItem);
			}
		};
	};
};