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
camera.position.x = 0;
camera.position.y = 0;
camera.position.z = 4;
controls.update();
// Cargar la imagen en una textura
var loader = new THREE.TextureLoader();
var texture = loader.load("./img/img-1.jpg");
// Crear una geometría (por ejemplo, un plano)
var geometry = new THREE.PlaneGeometry(8, 5);
// var material = new THREE.MeshPhongMaterial({color: 0xffffff}); // Material con iluminación
var material = new THREE.MeshLambertMaterial({map: texture});
var mesh = new THREE.Mesh(geometry, material);
// mesh.rotation.x = -Math.PI / 3;
scene.add(mesh);
// Agregar luces a la escena
var ambient_light = new THREE.AmbientLight(0x111111, 1);
var point_light = new THREE.PointLight(0xffffff, 1, 7);
scene.add(ambient_light);
scene.add(point_light);
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
  // mesh.rotation.x += 0.01;
  // mesh.rotation.y += 0.01;
  moveCamera();
  // La posición del punto de luz se actualiza en base a la posición de la cámara
  point_light.position.set(camera.position.x, camera.position.y, camera.position.z);
  controls.update();
  renderer.render(scene, camera);
}
animate();