var xValues = ["Carlos Mamani", "José Sanchez", "Marcos Flores", "Marta Quispe", "Miguel Choque"];
var yValues = [9, 8, 6, 9, 7, 10, 0];
var barColors = ["red", "green", "blue", "orange", "black"];
new Chart("myChart", {
  type: "bar",
  data: {
  labels: xValues,
  datasets: [{
    backgroundColor: barColors,
    data: yValues
  }]
  },
  options: {
    legend: { display: true },
    title: {
      display: true,
      text: "Asistencia de Estudiantes de ING Sistemas"
    }
  }
});