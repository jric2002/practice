$(document).ready(function () {
  /* DataTable */
  $("#tabla-productos").DataTable();
  /* Functions */
  $("button#actualizar-datos").each(function(index) {
    $(this).click(function() {
      $id_c = $(this).attr("id-p");
      $datos = $("td[id-producto=" + $id_c.toString() + "]");
      $form = $("form#form-actualizar-datos");
      $form.attr("action", "/productos/actualizar/" + $id_c.toString());
      $form.find("input[name=nombre]").val($datos[0].textContent);
      $form.find("input[name=precio]").val($datos[1].textContent);
    });
  });
})