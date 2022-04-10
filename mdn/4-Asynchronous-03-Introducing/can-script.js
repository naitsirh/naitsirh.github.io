// usamos fetch para recuperar los productos y pasarlos a init
// reportamos cualquier error que ocurra durante la operación de recuperación
// una vez que los productos han sido cargados y formateados correctamente como
// un objeto JSON usando response.json(), y ejecutamos la función initialize()
fetch('products.json').then(function(response) {
  return response.json();
}).then(function(json) {
  let products = json;
  initialize(products);
}).catch(function(err) {
  console.log('Fetch problem: ' + err.message);
});

// configura la lógica de la aplicación, declara las variables requeridas,
// contiene todas las demás funciones
function initialize(products) {
  // tomamos los elementos de la UI que necesitamos manipular
  const category = document.querySelector('#category');
  const searchTerm = document.querySelector('#searchTerm');
  const searchBtn = document.querySelector('button');
  const main = document.querySelector('main');

  // mantenemos un registro de cuáles fueron la última categoría y término de
  // búsqueda ingresados
  let lastCategory = category.value;
  // aún no se ha realizado ninguna búsqueda
  let lastSearch = '';

  // estos contienen los resultados del filtrado por categoría y término de
  // búsqueda
  // finalGroup contendrá los productos que deben mostrarse después de que la
  // búsqueda se ha hecho. Cada uno será una matriz que contiene objetos.
  // Cada objeto representará un producto
  let categoryGroup;
  let finalGroup;

  // Para empezar, configuramos finalGroup para que sea igual a toda la base de
  // datos de productos, luego ejecutamos updateDisplay(), para que TODOS los
  // productos se muestren inicialmente.
  finalGroup = products;
  updateDisplay();

  // Configuramos ambos para que sean iguales a una matriz vacía, a tiempo para
  // que se ejecuten las búsquedas
  categoryGroup = [];
  finalGroup = [];

  // cuando se hace clic en el botón de búsqueda, invoqua selectCategory() para
  // comenzar la ejecución de una búsqueda en para seleccionar la categoría de
  // productos que queremos mostrar
  searchBtn.onclick = selectCategory;

  function selectCategory(e) {
    // Use preventDefault () para detener el envío del formulario — eso arruinaría
    // la experiencia
    e.preventDefault();

    // Vuelvemos a establecerlos en matrices vacías, para borrar la búsqueda
    // anterior
    categoryGroup = [];
    finalGroup = [];

    // si la categoría y el término de búsqueda son los mismos que los de la
    // última vez que se ejecutó la búsqueda, los resultados serán los mismos,
    // entonces no tiene sentido correrla de nuevo, solo vuelve fuera la función
    if(category.value === lastCategory && searchTerm.value.trim() === lastSearch) {
      return;
    } else {
      // actualizamos el registro de la última categoría y término de búsqueda
      lastCategory = category.value;
      lastSearch = searchTerm.value.trim();
      // En este caso queremos seleccionar todos los productos, luego filtrarlos
      // por el término de búsqueda, así que simplemente configuramos
      // categoryGroup para todo el objeto JSON, y luego ejecutamos 
      // selectProducts()
      if(category.value === 'Todas') {
        categoryGroup = products;
        selectProducts();
      // Si se elige una categoría específica, debemos filtrar los productos que
      // no están en esa categoría, luego colocamos los productos restantes dentro
      // de categoryGroup, antes de ejecutar selectProducts()
      } else {
        // los valores de los elementos <option> están en mayúsculas, mientras
        // que las categorías almacenar en JSON (bajo "type") están en minúsculas.
        // Por lo tanto, necesitamos convertir a minúsculas antes de hacer una
        // comparación
        let lowerCaseType = category.value.toLowerCase();
        for(let i = 0; i < products.length ; i++) {
          // Si la propiedad de tipo de un producto es la misma que la categoría
          // elegida, queremos mostrarlo, por lo que lo mandamos a la matriz
          // categoryGroup
          if(products[i].type === lowerCaseType) {
            categoryGroup.push(products[i]);
          }
        }

        // ejecutamos selectProducts() después de que se haya realizado el
        // filtrado
        selectProducts();
      }
    }
  }

  // selectProducts() toma el grupo de productos seleccionados por
  // selectCategory(), y además los filtra por el término de búsqueda escalonado
  // (si se ha ingresado uno)
  function selectProducts() {
    // Si no se ha introducido ningún término de búsqueda, simplemente hacemos
    // que el arreglo finalGroup sea igual al arreglo categoryGroup — no queremos
    // filtrar más los productos — luego ejecutamos updateDisplay()
    if(searchTerm.value.trim() === '') {
      finalGroup = categoryGroup;
      updateDisplay();
    } else {
      // nos aseguramos de que el término de búsqueda se convierta a minúsculas
      // antes de realizar la comparación. Mantenemos los nombres de los productos
      // todos en minúsculas para simplificar las cosas
      let lowerCaseSearchTerm = searchTerm.value.trim().toLowerCase();
      // Para cada producto en categoryGroup, vemos si el término de búsqueda está
      // contenido dentro del nombre del producto (si el resultado de indexOf() no
      // retorna -1, significa que lo está) — si lo está, entonces mandamos el
      // producto a la matriz finalGroup
      for(let i = 0; i < categoryGroup.length ; i++) {
        if(categoryGroup[i].name.indexOf(lowerCaseSearchTerm) !== -1) {
          finalGroup.push(categoryGroup[i]);
        }
      }

      // ejecutamos updateDisplay() después de que se haya realizado esta segunda
      // ronda de filtrado
      updateDisplay();
    }

  }

  // iniciamos el proceso de actualización de la pantalla con el nuevo conjunto
  // de productos
  function updateDisplay() {
    // eliminamos el contenido anterior del elemento <main>
    while (main.firstChild) {
      main.removeChild(main.firstChild);
    }

    // si ningún producto coincide con el término de búsqueda, muestrmos un
    // mensaje de "No hay resultados para mostrar"
    if(finalGroup.length === 0) {
      const para = document.createElement('p');
      para.textContent = '¡No hay resultados para mostrar!';
      main.appendChild(para);
    // para cada producto que queremos mostrar, pasamos su objeto de producto a
    // fetchBlob()
    } else {
      for(let i = 0; i < finalGroup.length; i++) {
        fetchBlob(finalGroup[i]);
      }
    }
  }

  // fetchBlob utiliza fetch para recuperar la imagen de ese producto, y luego
  // envía la URL de visualización de la imagen resultante y el objeto de producto
  // en showProduct(), para finalmente mostrarlo
  function fetchBlob(product) {
    // construimos la ruta URL al archivo de imagen a partir de la propiedad
    // product.image
    let url = 'images/' + product.image;
    // usamos fetch para buscar la imagen y convertir la respuesta resultante en
    // un blob. Nuevamente, si ocurre algún error, lo informamos en la consola
    fetch(url).then(function(response) {
        return response.blob();
    }).then(function(blob) {
      // convertimos el blob en una URL de objeto — esto es básicamente una URL
      // interna temporal que apunta a un objeto almacenado dentro del navegador
      let objectURL = URL.createObjectURL(blob);
      // invocamos showProduct
      showProduct(objectURL, product);
    });
  }

  // mostramos un producto dentro del elemento <main>
  function showProduct(objectURL, product) {
    // creamos los elementos <section>, <h2>, <p>, e <img>
    const section = document.createElement('section');
    const heading = document.createElement('h2');
    const para = document.createElement('p');
    const image = document.createElement('img');

    // damos a <section> un nombre de clase igual a la propiedad "type" del
    // producto para que muestre el icono correcto
    section.setAttribute('class', product.type);

    // asignamos el <h2> textContent igual a la propiedad "nombre" del producto,
    // pero con el primer carácter reemplazado por mayúscula
    heading.textContent = product.name.replace(product.name.charAt(0), product.name.charAt(0).toUpperCase());

    // asignamos el <p> textContent igual a la propiedad "precio" del producto,
    // con un signo $ delante
    // toFixed(2) se usa para fijar el precio en 2 decimales, así por ejemplo 1.40
    // es mostrado como 1.40, no 1.4
    para.textContent = '$' + product.price.toFixed(2);

    // establezca el src del elemento <img> en ObjectURL y el alt en la propiedad
    // "nombre" del producto
    image.src = objectURL;
    image.alt = product.name;

    // agregamos los elementos al DOM según corresponda, agregando el producto a
    // la UI
    main.appendChild(section);
    section.appendChild(heading);
    section.appendChild(para);
    section.appendChild(image);
  }
}
