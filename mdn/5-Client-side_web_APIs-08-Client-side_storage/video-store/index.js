// creamos las constantes necesarias
const section = document.querySelector('section');
const videos = [
  { 'name' : 'CERDO' },
  { 'name' : 'CRISTAL' },
  { 'name' : 'DUENDE' },
  { 'name' : 'MONSTRUO' },
  { 'name' : 'RANA' },
  { 'name' : 'CONEJO' }
];




// creamos una instancia de objeto db para almacenar la base de datos abierta
let db;




function init() {
  // recorremos los nombres de los videos uno por uno
  for (const video of videos) {
    // abrimos transaction, obtenemos 'object store', y hacemos get() para cada
    // video por el nombre
    const objectStore = db.transaction('videos_os').objectStore('videos_os');
    const request = objectStore.get(video.name);
    request.addEventListener('success', () => {
      // si el resultado existe en la base de datos (no está indefinido)
      if (request.result) {
        // tomamos los videos desde la IDB y los mostramos usando displayVideo()
        console.log('Tomamos los videos desde la IDB');
        displayVideo(request.result.mp4, request.result.webm, request.result.name);
      } else {
        // obtenemos los videos de la red
        fetchVideoFromNetwork(video);
      }
    });
  }
};




// definimos la función fetchVideoFromNetwork()
function fetchVideoFromNetwork(video) {
  console.log('Recuperamos los videos de la red');
  // obtenemos las versiones MP4 and WebM  del video usando la función fetch(),
  // y luego exponemos sus cuerpos de respuesta como blobs
  const mp4Blob = fetch(`videos/${video.name}.mp4`).then(response => response.blob());
  const webmBlob = fetch(`videos/${video.name}.webm`).then(response => response.blob());


  // sólo ejecutamos el siguiente código cuando ambas promesas se hayan cumplido
  Promise.all([mp4Blob, webmBlob]).then(values => {
    // mostramos el video obtenido de la red con displayVideo()
    displayVideo(values[0], values[1], video.name);
    // lo almacenamos en la IDB usando storeVideo()
    storeVideo(values[0], values[1], video.name);
  });
};




// definimos la función storeVideo()
function storeVideo(mp4Blob, webmBlob, name) {
  // abrimos transaction, obtenemos 'object store'; lo convertimos en lectura /
  // escritura para que podamos escribir en la IDB
  const objectStore = db.transaction(['videos_os'], 'readwrite').objectStore('videos_os');
  // creamos un registro para agregar a la IDB
  const record = {
    mp4 : mp4Blob,
    webm : webmBlob,
    name : name
  };


  // agregamos el registro a la IDB usando add()
  const request = objectStore.add(record);


  request.addEventListener('success', () => console.log('Intento de adición de registros finalizado'));
  request.addEventListener('error', () => console.error(request.error));
};




// definimos la función displayVideo()
function displayVideo(mp4Blob, webmBlob, title) {
  // creamos las direcciones URL de objetos a partir de los blobs
  const mp4URL = URL.createObjectURL(mp4Blob);
  const webmURL = URL.createObjectURL(webmBlob);


  // creamos los elementos DOM para incrustar video en la página
  const article = document.createElement('article');
  const h2 = document.createElement('h2');
  h2.textContent = title;
  const video = document.createElement('video');
  video.controls = true;
  const source1 = document.createElement('source');
  source1.src = mp4URL;
  source1.type = 'video/mp4';
  const source2 = document.createElement('source');
  source2.src = webmURL;
  source2.type = 'video/webm';


  // cargamos los elementos DOM en la página
  section.appendChild(article);
  article.appendChild(h2);
  article.appendChild(video);
  video.appendChild(source1);
  video.appendChild(source2);
};




// abrimos la base de datos; la misma es creada si todavía no existe
// (ver upgradeneeded más abajo)
const request = window.indexedDB.open('videos_db', 1);




// el controlador 'error' indica que la base de datos no se abrió correctamente
request.addEventListener('error', () => console.error('Error al abrir la base de datos'));




// el controlador 'success' indica que la base de datos se abrió correctamente
request.addEventListener('success', () => {
  console.log('Base de datos abierta con éxito');


  // almacenamos el objeto de base de datos abierto en la variable db. Esto se 
  // usa a continuación
  db = request.result;
  init();
});




// configuramos las tablas de la base de datos si aún no se ha hecho
request.addEventListener('upgradeneeded', e => {


  // tomamos una referencia a la base de datos abierta
  const db = e.target.result;


  // creamos un objectStore para almacenar nuestros videos en él (básicamente
  // como una sola tabla) incluyendo una clave de incremento automático
  const objectStore = db.createObjectStore('videos_os', { keyPath: 'name' });


  // definimos qué elementos de datos contendrá el objectStore
  objectStore.createIndex('mp4', 'mp4', { unique: false });
  objectStore.createIndex('webm', 'webm', { unique: false });


  console.log('Configuración de la base de datos completa');
});