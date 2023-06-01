$(document).ready(function(){
  $base_url = window.location.protocol + "//" + window.location.host + "/";
  $.ajax({
    url: $base_url + "ventas-por-dia",
    dataType: "json",
    beforeSend: function(){
      console.log("Cargando información de Ventas por Dia...");
    },
    success: function(datos){
      l = datos.map(function(e, i, a) {
        return e["fecha_venta"];
      });
      d = datos.map(function(e, i, a) {
        return e["cantidad_ventas"];
      });
      const data_vps = {
        labels: l,
        datasets: [{
          label: "Ventas por dia",
          data: d,
          backgroundColor: [
            'rgba(255, 99, 132, 0.2)',
            'rgba(153, 102, 255, 0.2)',
            'rgba(54, 162, 235, 0.2)',
            'rgba(255, 159, 64, 0.2)',
            'rgba(255, 205, 86, 0.2)',
            'rgba(75, 192, 192, 0.2)',
            'rgba(201, 203, 207, 0.2)'
          ],
          borderColor: [
            'rgb(255, 99, 132)',
            'rgb(153, 102, 255)',
            'rgb(54, 162, 235)',
            'rgb(255, 159, 64)',
            'rgb(255, 205, 86)',
            'rgb(75, 192, 192)',
            'rgb(201, 203, 207)'
          ],
          borderWidth: 1
        }]
      };
      const conf_vpd = {
        type: 'bar',
        data: data_vps,
        options: {
          scales: {
            y: {
              beginAtZero: true
            }
          }
        },
      };
      const ventas_por_dia = new Chart(
        document.getElementById('ventas-por-dia'),
        conf_vpd
      );
    }
  });
  $.ajax({
    url: $base_url + "clientes-por-ventas",
    dataType: "json",
    beforeSend: function(){
      console.log("Cargando información de Clientes por Ventas...");
    },
    success: function(datos){
      l = datos.map(function(e, i, a) {
        return (e["nombres"] + " " + e["apellidos"]);
      });
      d = datos.map(function(e, i, a) {
        return e["venta_total"];
      });
      const data_cpv = {
        labels: l,
        datasets: [{
          label: "Clientes por Ventas",
          data: d,
          backgroundColor: [
            'rgba(255, 99, 132, 0.2)',
            'rgba(54, 162, 235, 0.2)',
            'rgba(153, 102, 255, 0.2)',
            'rgba(255, 159, 64, 0.2)',
            'rgba(255, 205, 86, 0.2)',
            'rgba(75, 192, 192, 0.2)',
            'rgba(201, 203, 207, 0.2)'
          ],
          borderColor: [
            'rgb(255, 99, 132)',
            'rgb(54, 162, 235)',
            'rgb(153, 102, 255)',
            'rgb(255, 159, 64)',
            'rgb(255, 205, 86)',
            'rgb(75, 192, 192)',
            'rgb(201, 203, 207)'
          ],
          borderWidth: 1
        }]
      };
      const conf_cpv = {
        type: 'bar',
        data: data_cpv,
        options: {
          scales: {
            y: {
              beginAtZero: true
            }
          }
        },
      };
      const ventas_por_dia = new Chart(
        document.getElementById('clientes-por-ventas'),
        conf_cpv
      );
    }
  });
});