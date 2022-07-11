//FUNCION CALLBACK
/*function saludo(nombre) {
    setTimeout(() => {
        console.log(nombre);
    }, 3000);
}
function ingrese(callback) {
    const nombre = "jose";
    callback(nombre);
    console.log("esto se ejecuta primero")
}
ingrese(saludo);*/

//ASYNC - ASINCRONISMO
/*
let promesa = new Promise(function(resolve, rejected) {
    setTimeout(() => resolve("timeout"), 2000);
});
promesa.then(data => console.log(data)).catch(error => console.log(error));*/
/*
function convertirMin(text) {
    return new Promise(function(resolve, rejected) {
        resolve(text.toLowerCase());
    });
}
async function mensaje(data) {
    console.log(convertirMin(data));
    const result = await convertirMin(data);
    console.log(result);
}
mensaje("hola mundo");*/