const displayedImage = document.querySelector('.displayed-img');
const thumbBar = document.querySelector('.thumb-bar');

const btn = document.querySelector('button');
const overlay = document.querySelector('.overlay');

// Recorriendo las imágenes
for (let i = 1; i <= 5; i++) {
	const newImage = document.createElement('img');
	newImage.setAttribute('src', 'images/pic' + i + '.jpg');
	thumbBar.appendChild(newImage);
	newImage.onclick = function(e) {
		displayedImage.src = e.target.src;
	}
}


// Conectando el botón Oscurecer/Aclarar
btn.onclick = function() {
	const btnClass = btn.getAttribute('class');
	if (btnClass === 'dark') {
		btn.setAttribute('class', 'light');
		btn.textContent = 'Aclarar';
		overlay.style.backgroundColor = 'rgba(0,0,0,0.5)';
	} else {
		btn.setAttribute('class', 'dark');
		btn.textContent = 'Oscurecer';
		overlay.style.backgroundColor = 'rgba(0,0,0,0)';
	}
}