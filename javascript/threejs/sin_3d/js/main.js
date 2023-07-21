import * as THREE from "three";
// Obtén una referencia al lienzo
const canvas = document.getElementById('canvas');
canvas.width = 500;
canvas.height = 500;
// Crea una escena
const scene = new THREE.Scene();
// Crea una cámara
const camera = new THREE.PerspectiveCamera(75, canvas.clientWidth / canvas.clientHeight, 0.1, 1000);
camera.position.z = 1;
// camera.position.y = 1;
// camera.position.z = 5;
// Crea un renderizador
const renderer = new THREE.WebGLRenderer({canvas});
// Crea una geometría para el gráfico del seno
const geometry = new THREE.BufferGeometry();
const num_points = 1000;
let points = [];
for (let i = 0; i < num_points; i++) {
  let x = (i/100) - 5;
  let y = Math.sin(x);
  let z = 0;
  points.push(new THREE.Vector3(x, y, z));
}
geometry.setFromPoints(points);
// Crea un material para el gráfico del seno
const material = new THREE.LineBasicMaterial({ color: 0x00ff00 });
// Crea una línea utilizando la geometría y el material
const line = new THREE.Line(geometry, material);
// Agrega la línea a la escena
scene.add(line);
// Renderiza la escena
function animate() {
  requestAnimationFrame(animate);
  renderer.render(scene, camera);
}
animate();