// 1. DEFINICIONES DE VARIABLES Y FUNCIONES

const customName = document.getElementById('customname');
const randomize = document.querySelector('.randomize');
const story = document.querySelector('.story');

function randomValueFromArray(array){
  const random = Math.floor(Math.random()*array.length);
  return array[random];
}


// 2. CADENAS DE TEXTO INICIALES

let storyText = 'Hacía 94 grados fahrenheit afuera, entonces :insertx: se fue a \
	dar un paseo. Cuando llegó a:inserty:, se quedó horrrizado por un momento, \
	y entonces :insertz:. Bob lo vio todo, pero no se sorprendió — :insertx: \
	pesaba 300 libras, y era un día muy caluroso.';

let insertX = ['Pombero el Duende',
			   'Pie Grande',
			   'Papá Noel'];
let insertY = ['l comedor comunitario',
			   ' Narnia', 
			   ' la Casa Rosada'];
let insertZ = ['se quemó espontáneamente',
			   'quedó derretido en un charco en la acera',
			   'se convirtió en una babosa y se fue arrastrando'];


// 3. DEFINICION DEL CAPTURADOR/DETECTOR DE EVENTO Y FUNCION 'RESULT'

randomize.addEventListener('click', result);

function result() {
	let newStory = storyText;

	let xItem = randomValueFromArray(insertX);
	let yItem = randomValueFromArray(insertY);
	let zItem = randomValueFromArray(insertZ);

	newStory = newStory.replace(':insertx:', xItem);
	newStory = newStory.replace(':insertx:', xItem);
	newStory = newStory.replace(':inserty:', yItem);
	newStory = newStory.replace(':insertz:', zItem);

  if(customName.value !== '') {
    let name = customName.value;
    newStory = newStory.replace('Bob', name);
  }

  if(document.getElementById("uk").checked) {
    let weight = Math.round(300 * 0.453592) + ' kilos';
    let temperature =  Math.round((94 - 32) * 5 / 9) + ' grados centígrados';
    newStory = newStory.replace('94 grados fahrenheit', temperature);
    newStory = newStory.replace('300 libras', weight);
  }

  story.textContent = newStory;
  story.style.visibility = 'visible';
}