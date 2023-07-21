import * as THREE from "three";
import { OrbitControls } from 'three/addons/controls/OrbitControls.js';
// Obtén una referencia al lienzo
const canvas = document.getElementById('canvas');
canvas.width = 1280;
canvas.height = 720;
var keyboard = {};
// Crea una escena
const scene = new THREE.Scene();
// Crear el renderizador
var renderer = new THREE.WebGLRenderer({canvas});
// Crea una cámara
const camera = new THREE.PerspectiveCamera(75, canvas.clientWidth / canvas.clientHeight, 0.1, 1000);
const controls = new OrbitControls(camera, renderer.domElement);
camera.position.x = 5;
camera.position.y = 0;
camera.position.z = 5;
controls.update();
// Cargar la imagen en una textura
var loader = new THREE.TextureLoader();
var texture1 = loader.load("./img/img-1.jpg");
var texture2 = loader.load("./img/img-2.jpg");
// Crea un objeto contenedor para las imágenes
const container = new THREE.Object3D();
// Crear una geometría (por ejemplo, un plano)
var geometry = new THREE.PlaneGeometry(9, 6);
// var material = new THREE.MeshPhongMaterial({color: 0xffffff}); // Material con iluminación
var material1 = new THREE.MeshLambertMaterial({map: texture1});
var plane1 = new THREE.Mesh(geometry, material1);
plane1.position.set(1, 0, 0);
var material2 = new THREE.MeshLambertMaterial({map: texture2});
var plane2 = new THREE.Mesh(geometry, material2);
plane2.position.set(-5, 0, 5);
container.add(plane1);
container.add(plane2);
scene.add(container);
// Agregar luces a la escena
var ambient_light = new THREE.AmbientLight(0xcccccc, 1);
scene.add(ambient_light);
// Función para mover la cámara
function moveCamera() {
  if (keyboard[87]) { // W key - Mover hacia arriba
    camera.position.y += 0.1;
  }
  if (keyboard[83]) { // S key - Mover hacia abajo
    camera.position.y -= 0.1;
  }
  if (keyboard[65]) { // A key - Mover hacia la izquierda
    camera.position.x -= 0.1;
  }
  if (keyboard[68]) { // D key - Mover hacia la derecha
    camera.position.x += 0.1;
  }
}
// Función para manejar eventos de teclado
function keyPressed(event) {
  keyboard[event.keyCode] = true;
}
function keyReleased(event) {
  keyboard[event.keyCode] = false;
}
// Escuchar eventos de teclado
document.addEventListener('keydown', keyPressed);
document.addEventListener('keyup', keyReleased);
// Renderizar la escena
function animate() {
  requestAnimationFrame(animate);
  plane1.rotation.y += 0.03;
  plane2.rotation.y += 0.03;
  moveCamera();
  controls.update();
  renderer.render(scene, camera);
}
animate();