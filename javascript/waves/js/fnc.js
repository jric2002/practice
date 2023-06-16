// https://www.youtube.com/watch?v=VNmTubIDZOY
// https://www.youtube.com/c/ChrisCourses/videos
// https://www.npmjs.com/package/dat.gui
// https://www.mathsisfun.com/geometry/unit-circle.html


//import * as dat from '../node_modules/dat.gui/build/dat.gui';
 
const gui = new dat.GUI();

const canvas = document.getElementById('canvas');
const ctx = canvas.getContext('2d');

canvas.width = window.innerWidth;
canvas.height = window.innerHeight;

/* ctx.beginPath();
ctx.moveTo(0, canvas.height/2);
for(let i=0; i<canvas.width; i++) {
    ctx.lineTo(i, canvas.height/2 + Math.sin(i*0.1) * 100);
}
ctx.stroke(); */

const wave = {
    y           : canvas.height/2,
    length      : 0.01,
    amplitude   : 100,
    frequency   : 0.01
};

const strokeColor = {
    h: 150,
    s: 50,
    l: 50
};

const backgroundColor = {
    r: 0,
    g: 0,
    b: 0,
    a: 0.01
};

/* gui.add(wave, 'y', 0, canvas.height);
gui.add(wave, 'length', -0.01, 0.01);
gui.add(wave, 'amplitude', -200, 200);
gui.add(wave, 'frequency', -0.01, 1);
gui.add(strokeColor, 'h', 0, 255); */

const waveFolder = gui.addFolder('Parámetros de Ondas');
const strokeFolder = gui.addFolder('Colores');
const backgroundFolder = gui.addFolder('Color de Fondo');

waveFolder.add(wave, 'y', 0, canvas.height);
waveFolder.add(wave, 'length', -0.01, 0.01);
waveFolder.add(wave, 'amplitude', -200, 200);
waveFolder.add(wave, 'frequency', -0.01, 1);
waveFolder.open();

strokeFolder.add(strokeColor, 'h', 0, 255);
strokeFolder.add(strokeColor, 's', 0, 100);
strokeFolder.add(strokeColor, 'l', 0, 100);
strokeFolder.open();

backgroundFolder.add(backgroundColor, 'r', 0, 255);
backgroundFolder.add(backgroundColor, 'g', 0, 255);
backgroundFolder.add(backgroundColor, 'b', 0, 255);
backgroundFolder.add(backgroundColor, 'a', 0, 1);
backgroundFolder.open();

let increment = wave.frequency;
function animate() {
    requestAnimationFrame(animate);

    // ctx.fillStyle = 'rgba(0, 0, 0, 0.01)';
    ctx.fillStyle = `rgba(${backgroundColor.r}, ${backgroundColor.g}, ${backgroundColor.b}, ${backgroundColor.a})`;
    ctx.fillRect(0, 0, canvas.width, canvas.height);
    //ctx.clearRect(0, 0, canvas.width, canvas.height);

    ctx.beginPath();
    ctx.moveTo(0, canvas.height/2);
    for(let i=0; i<canvas.width; i++) {
        // ctx.lineTo(i, wave.y + Math.sin(i * wave.length + increment) * wave.amplitude);

        // cambiamos para un escenario ondeante
        ctx.lineTo(i, wave.y + Math.sin(i * wave.length + increment) * wave.amplitude * Math.sin(increment));
        // ctx.lineTo(i, wave.y + ((Math.sin(i * wave.length + increment) * wave.amplitude)/i)*100);
    }

    // ctx.strokeStyle = 'hsl(0, 50%, 50%)';
    // ctx.strokeStyle = `hsl(${strokeColor.h}, ${strokeColor.s}%, ${strokeColor.l}%)`;
    // ctx.strokeStyle = `hsl(${strokeColor.h * Math.sin(increment)}, ${strokeColor.s}%, ${strokeColor.l}%)`;
    ctx.strokeStyle = `hsl(${Math.abs(strokeColor.h * Math.sin(increment))}, ${strokeColor.s}%, ${strokeColor.l}%)`;
    ctx.stroke();
    increment += wave.frequency;
}

animate();