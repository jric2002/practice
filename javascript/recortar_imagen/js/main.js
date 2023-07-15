// Crear el lienzo (canvas)
var canvas = document.createElement("canvas");
var ctx = canvas.getContext("2d");
// Cargar las dos imágenes secuenciales
var img1 = new Image();
img1.src = "./img/rain-1.jpg";
var img2 = new Image();
img2.src = "./img/rain-2.jpg";
// Esperar a que ambas imágenes se carguen
img1.onload = function() {
  img2.onload = function() {
    // Obtener datos de las imágenes
    let img1_pxls = (ctx.getImageData(0, 0, img1.width, img1.height)).data;
    let img2_pxls = (ctx.getImageData(0, 0, img2.width, img2.height)).data;
    // Buscando pixeles comúnes de las 2 imágenes
    let pxls_c = [];
    for (let i = 0; i < img1_pxls.length; i += 4) {
      let r1 = img1_pxls[i];
      let g1 = img1_pxls[i + 1];
      let b1 = img1_pxls[i + 2];
      let t1 = img1_pxls[i + 3];
      for (let j = 0; j < img2_pxls.length; j += 4) {
        let r2 = img1_pxls[i];
        let g2 = img1_pxls[i + 1];
        let b2 = img1_pxls[i + 2];
        let t2 = img1_pxls[i + 3];
        if (r1 == r2 && g1 == g2 && b1 == b2) {
          pxls_c.push(r1, g1, b1, t1);
        }
        break;
      }
    }
    // Crear una nueva imágen a partir de la matrix de pixeles comúnes
    let img_pan = new ImageData(new Uint8ClampedArray(pxls_c), img1.width, img1.height);
    canvas.width = img1.width;
    canvas.height = img1.height;
    ctx.putImageData(img_pan, 0, 0);
  };
};