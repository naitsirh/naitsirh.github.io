// creamos las constantes necesarias
const rememberDiv = document.querySelector('.remember');
const forgetDiv = document.querySelector('.forget');
const form = document.querySelector('form');
const nameInput = document.querySelector('#entername');
const submitBtn = document.querySelector('#submitname');
const forgetBtn = document.querySelector('#forgetname');

const h1 = document.querySelector('h1');
const personalGreeting = document.querySelector('.personal-greeting');

// detenemos el envío del formulario cuando se presiona un botón
form.addEventListener('submit', function(e) {
	e.preventDefault();
});

// ejecutamos la función cuando se hace clic en el botón 'Di hola'
submitBtn.addEventListener('click', function() {
	// almacenamos el nombre ingresado en el almacenamiento web
	localStorage.setItem('name', nameInput.value);
	// ejecutamos nameDisplayCheck() para ordenar la visualización de los saludos
	// personalizados y actualizamos la visualización del formulario
	nameDisplayCheck();
});

// ejecutamos la función cuando se hace clic en el botón 'Olvídame'
forgetBtn.addEventListener('click', function() {
	// eliminamos el nombre almacenado del almacenamiento web
	localStorage.removeItem('name');
	// ejecutamos nameDisplayCheck() para ordenar la visualización del saludo genérico
	// de nuevo y actualizamos la visualización del formulario
	nameDisplayCheck();
});

// definimos la función nameDisplayCheck()
function nameDisplayCheck() {
	// comprobamos si el elemento de datos 'nombre' está almacenado en el
	// almacenamiento web
	if (localStorage.getItem('name')) {
		// si es así, mostramos un saludo personalizado
		let name = localStorage.getItem('name');
		h1.textContent = 'Bienvenid@, ' + name;
		personalGreeting.textContent = 'Bienvenid@ a nuestro sitio web, ' + name +
			'! Esperamos que te diviertas mientras estás aquí.';
		// ocultamos la parte 'recordar' del formulario y mostramos la parte 'olvidar'
		forgetDiv.style.display = 'block';
		rememberDiv.style.display = 'none';
	} else {
		// si no es así, mostramos el saludo genérico
		h1.textContent = 'Bienvenid@ a nuestro sitio web.';
		personalGreeting.textContent = 'Bienvenid@ a nuestro sitio web. Eperamos que te diviertas mientras estás aquí.';
		// ocultamos la parte 'olvidar' del formulario y mostramos la parte 'recordar'
		forgetDiv.style.display = 'none';
		rememberDiv.style.display = 'block';
	}
};

// ejecutamos nameDisplayCheck() cuando el DOM se carga por primera vez para
// verificar si un nombre personal fue previamente configurado, y si es así mostrar
// el saludo personalizado. Si no, mostramos el saludo genérico
document.body.onload = nameDisplayCheck;