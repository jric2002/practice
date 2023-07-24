// Crear el lienzo (canvas)
var canvas = document.getElementById("canvas");
var ctx = canvas.getContext("2d");
// Cargar las dos imágenes secuenciales
var img1 = new Image();
img1.src = "./img/rss-rain-1.jpg";
var img2 = new Image();
img2.src = "./img/rss-rain-2.jpg";
// Esperar a que ambas imágenes se carguen
img1.onload = function() {
  canvas.width = img1.width;
  canvas.height = img1.height;
  ctx.drawImage(img1, 0, 0, img1.width, img1.height);
  let img1_data = ctx.getImageData(0, 0, canvas.width, canvas.height);
  let img1_pxls = img1_data.data;
  img2.onload = function() {
    ctx.clearRect(0, 0, canvas.width, canvas.height);
    canvas.width = img2.width;
    canvas.height = img2.height;
    ctx.drawImage(img2, 0, 0, img2.width, img2.height);
    // Obtener datos de las imágenes
    let img2_data = ctx.getImageData(0, 0, canvas.width, canvas.height);
    let img2_pxls = img2_data.data;
    // Buscando la posición del los primeros pixeles comúnes
    let i = 0, j;
    let c_pxls = []
    let s = true;
    while (i < img1_pxls.length) {
      let r1 = img1_pxls[i];
      let g1 = img1_pxls[i + 1];
      let b1 = img1_pxls[i + 2];
      let t1 = img1_pxls[i + 3];
      if (s) {
        j = 0;
      }
      let r2 = img2_pxls[j];
      let g2 = img2_pxls[j + 1];
      let b2 = img2_pxls[j + 2];
      let t2 = img2_pxls[j + 3];
      if (r1 == r2 && g1 == g2 && b1 == b2) {
        j += 4;
        s = false;
        c_pxls.push(r2, g2, b2, t2);
        break;
      }
      i += 4;
    }
    ctx.clearRect(0, 0, canvas.width, canvas.height);
    // Crear una imagen de píxeles a partir del array
    const image_data = ctx.createImageData(img1.width, img1.height);
    const data = image_data.data;
    for (let i = 0; i < c_pxls.length; i++) {
      const indice = i * 4;
      data[indice] = c_pxls[i]; // Componente rojo del píxel
      data[indice + 1] = c_pxls[i + 1]; // Componente verde del píxel
      data[indice + 2] = c_pxls[i + 2]; // Componente azul del píxel
      data[indice + 3] = c_pxls[i + 3]; // Componente alpha (transparencia) del píxel
    }
    // Dibujar la imagen en el canvas
    ctx.putImageData(image_data, 0, 0);
  }
};