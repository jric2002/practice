// Crear el lienzo (canvas)
var canvas = document.getElementById("canvas");
var ctx = canvas.getContext("2d");
// Cargar las dos imágenes secuenciales
var img1 = new Image();
img1.src = "./img/rain-1.jpg";
var img2 = new Image();
img2.src = "./img/rain-2.jpg";
// Esperar a que ambas imágenes se carguen
img1.onload = function() {
  canvas.width = img1.width;
  canvas.height = img1.height;
  ctx.drawImage(img1, 0, 0, img1.width, img1.height);
  let img1_data = ctx.getImageData(0, 0, img1.width, img1.height);
  let img1_pxls = img1_data.data;
  img2.onload = function() {
    ctx.clearRect(0, 0, canvas.width, canvas.height);
    canvas.width = img2.width;
    canvas.height = img2.height;
    ctx.drawImage(img2, 0, 0, img2.width, img2.height);
    // Obtener datos de las imágenes
    let img2_data = ctx.getImageData(0, 0, img2.width, img2.height);
    let img2_pxls = img2_data.data;
    // Buscando la posición del los primeros pixeles comúnes
    let r2 = img2_pxls[0];
    let g2 = img2_pxls[1];
    let b2 = img2_pxls[2];
    let t2 = img2_pxls[3];
    let i = 0;
    while (i < img1_pxls.length) {
      let r1 = img1_pxls[i];
      let g1 = img1_pxls[i + 1];
      let b1 = img1_pxls[i + 2];
      let t1 = img1_pxls[i + 3];
      if (r1 == r2 && g1 == g2 && b1 == b2) {
        break;
      }
      i += 4;
    }
    ctx.clearRect(0, 0, canvas.width, canvas.height);
    // Establecer el ancho y alto de canvas para mostrar las imágenes
  }
};

/* // Carga las imágenes
let img1 = cv.imread(document.getElementById("image-1"));
let img2 = cv.imread(document.getElementById("image-2"));
// Crea una matriz vacía para almacenar la imagen de intersección
let intersection = new cv.Mat();
// Encuentra la intersección entre ambas imágenes
cv.bitwise_and(img1, img2, intersection);
// Convierte la imagen de intersección a escala de grises
cv.cvtColor(intersection, intersection, cv.COLOR_BGR2GRAY);
// Encuentra los contornos de la imagen de intersección
let contours = new cv.MatVector();
let hierarchy = new cv.Mat();
cv.findContours(intersection, contours, hierarchy, cv.RETR_CCOMP, cv.CHAIN_APPROX_SIMPLE);
// Encuentra el rectángulo que contiene la intersección
let rect = cv.boundingRect(contours.get(0));
// Recorta la imagen original utilizando las coordenadas del rectángulo
let intersectionImg = img1.roi(rect);
// Dibuja el rectángulo en la imagen original para resaltar la intersección
cv.rectangle(img1, { x: rect.x, y: rect.y }, { x: rect.x + rect.width, y: rect.y + rect.height }, [0, 255, 0, 255], 2);
// Muestra las imágenes resultantes
cv.imshow("canvas", img1);
// cv.imshow("Intersección", intersectionImg);
cv.waitKey(); */