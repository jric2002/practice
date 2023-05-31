const app = Vue.createApp({
  data() {
    return {
      titulo: "Lista de Tareas",
      tareas: [
        {
          texto: "Aprender Vue.js",
          terminada: false
        },
        {
          texto: "Aprender Angular 2",
          terminada: false
        },
        {
          texto: "Aprender Ionic 2",
          terminada: false
        }
      ],
      nuevaTarea: ""
    };
  },
  methods: {
    agregarTarea: function() {
      var texto = this.nuevaTarea.trim();
      if (texto) {
        this.tareas.push({
          texto: texto,
          terminada: false
        });
      }
      this.nuevaTarea = "";
    },
    borrar: function(indice) {
      this.tareas.splice(indice, 1);
    },
    tareaTerminada: function(indice) {
      this.tareas[indice].terminada = true;
      setTimeout(() => {
        this.tareas.splice(indice, 1);
      }, 3000);
    }
  }
});

const mountApp = app.mount("#app-1");