$(document).ready(function () {
  /* DataTable */
  $("#tabla-clientes").DataTable();
  /* Functions */
  $("button#actualizar-datos").each(function(index) {
    $(this).click(function() {
      $id_c = $(this).attr("id-c");
      $datos = $("td[id-cliente=" + $id_c.toString() + "]");
      $form = $("form#form-actualizar-datos");
      $form.attr("action", "/clientes/actualizar/" + $id_c.toString());
      $form.find("input[name=nombres]").val($datos[0].textContent);
      $form.find("input[name=apellidos]").val($datos[1].textContent);
      $form.find("input[name=direccion]").val($datos[2].textContent);
    });
  });
})