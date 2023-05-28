const canvas = document.getElementById('canvas');
const ctx = canvas.getContext('2d');

const image = new Image();
image.onload = mostrarImagen;
image.src = './imgs/sillustani.jpg';

function mostrarImagen()
{
    canvas.width = image.width;
    canvas.height = image.height;
    
    ctx.drawImage(image, 0, 0, image.width, image.height);
    escalaGrises(canvas);
}

function escalaGrises(canvas){
    var imgData = ctx.getImageData(0,0, canvas.width, canvas.height);
    var pixeles = imgData.data;
    
    for(let i=0; i<pixeles.length; i+=4){
        let R = pixeles[i];
        let G = pixeles[i+1];
        let B = pixeles[i+2];
        let T = pixeles[i+3];
        
        gris = (R+G+B)/3;
        
        pixeles[i] = gris;
        pixeles[i+1] = gris;
        pixeles[i+2] = gris;
    }
    ctx.putImageData(imgData,0,0);
}