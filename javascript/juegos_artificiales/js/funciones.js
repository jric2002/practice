var gravedad = .3;
var numHijos = 50;

var numParticulas = 20;
var particulasCreadas = 0;

function crearParticula() {
    var particula = document.createElement("div");
    particula.className = "particula";

    var x = Math.random() * window.innerWidth;
    var y = window.innerHeight;
    //var y = Math.random() * window.innerHeight;

    particula.style.top = y+"px";
    particula.style.left = x+"px";

    var velocidadY = -10 -(Math.random() * 10)

    particula.setAttribute("data-velocidad-y", velocidadY);
    particula.setAttribute("data-velocidad-x", "0");
    particula.setAttribute("data-padre", "true");
    particula.style.background = getRandomColor();

    document.getElementsByTagName("body")[0].append(particula);

    particulasCreadas++;

    if (particulasCreadas < numParticulas) {
        setTimeout(crearParticula, 50 + (Math.random() * 450));
    }
}
function iniciar() {
    //var particulas = document.getElementsByClassName("particula");
    /* for ( var p = 0; p < numParticulas; p++) {
        //var particula = particulas[p];
        var particula = document.createElement("div");
        particula.className = "particula";

        var x = Math.random() * window.innerWidth;
        var y = window.innerHeight;
        //var y = Math.random() * window.innerHeight;

        particula.style.top = y+"px";
        particula.style.left = x+"px";

        var velocidadY = -10 -(Math.random() * 10)

        particula.setAttribute("data-velocidad-y", velocidadY);
        particula.setAttribute("data-velocidad-x", "0");
        particula.setAttribute("data-padre", "true");
        particula.style.background = getRandomColor();

        document.getElementsByTagName("body")[0].append(particula);
    } */
    crearParticula();
}

function actualizar() {
    var particulas = document.getElementsByClassName("particula");
    for ( var p = 0; p < particulas.length; p++) {
        var particula = particulas[p];

        var velocidadY = parseFloat(particula.getAttribute("data-velocidad-y"));
        velocidadY += gravedad;

        particula.setAttribute("data-velocidad-y", velocidadY);

        var top = particula.style.top ? particula.style.top : "0";
        top = parseFloat(top.replace("px", ""));
        top += velocidadY;
        particula.style.top = top + "px";

        var velocidadX = parseFloat(particula.getAttribute("data-velocidad-x"));

        var left = particula.style.left ? particula.style.left : "0";
        left = parseFloat(left.replace("px", ""));
        left += velocidadX;
        particula.style.left = left + "px";

        var padre = particula.getAttribute("data-padre");

        if (velocidadY >=0 && padre === "true") {
            explotar(particula)
        }

        if (top > window.innerHeight) {
            particula.remove();
        }
    }

    setTimeout(actualizar, 20)
}

function explotar(particula) {
    // Aqui todo el codigo
    for (var h = 0; h < numHijos; h++) {
        var hijo = document.createElement("div")
        hijo.className = "particula";

        hijo.style.top = particula.style.top
        hijo.style.left = particula.style.left
        hijo.style.background = particula.style.background;

        var velocidadY = (Math.random() * 7) - 5;
        hijo.setAttribute("data-velocidad-y", velocidadY);
        var velocidadX = (Math.random() * 10) - 5;
        hijo.setAttribute("data-velocidad-x", velocidadX);

        hijo.setAttribute("data-padre", false);

        document.getElementsByTagName("body")[0].append(hijo);
    }

    particula.remove();
}

window.onload = function() {
    
    iniciar();
    actualizar();
}

function getRandomColor() {
    var letters = '0123456789ABCDEF';
    var color = '#';
    for (var i = 0; i < 6; i++) {
      color += letters[Math.floor(Math.random() * 16)];
    }
    return color;
  }