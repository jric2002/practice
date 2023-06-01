$(document).ready(function () {
  $base_url = window.location.protocol + "//" + window.location.host + "/";
  /* DataTable */
  $("#tabla-ventas").DataTable();
  $("#registrar-venta").click(function() {
    $.ajax({
      url: $base_url + "ventas/obtener-clientes",
      dataType: "json",
      beforeSend: function(){
        console.log("Cargando información de clientes");
      },
      success: function(datos){
        var se = document.getElementById("cliente");
        for (cliente of datos) {
          var op = document.createElement("option");
          op.value = cliente["id_cliente"];
          op.textContent = cliente["nombres"] + " " + cliente["apellidos"];
          se.appendChild(op);
        }
      }
    });
    var fecha_venta = document.getElementById("fecha-venta");
    var date = new Date().toLocaleDateString().split('/');
    var year = date[2];
    var month = (parseInt(date[1]) < 10) ? '0' + date[1] : date[1];
    var day = (parseInt(date[0]) < 10) ? '0' + date[0] : date[0];
    fecha_venta.value = year + '-' + month + '-' + day;
    var $productos = [];
    $.ajax({
      url: $base_url + "ventas/obtener-productos",
      dataType: "json",
      beforeSend: function(){
        console.log("Cargando información de productos");
      },
      success: function(datos){
        $productos = [...datos];
      }
    });
    $("button#agregar-producto").click(function() {
      var fila_total = document.getElementById("total");
      var tr = document.createElement("tr");
      tr.classList.add("producto-para-venta");
      tr.id = "producto-para-venta";
      var td_nombre = document.createElement("td");
      var td_pu = document.createElement("td");
      td_pu.classList.add("precio-unitario");
      td_pu.id = "precio-unitario";
      var td_cantidad = document.createElement("td");
      var input_cantidad = document.createElement("input");
      input_cantidad.type = "number";
      input_cantidad.id = "cantidad";
      input_cantidad.classList.add("cantidad");
      input_cantidad.value = 0;
      input_cantidad.min = 0;
      input_cantidad.style.width = "75px";
      var td_puxcantidad = document.createElement("td");
      td_puxcantidad.classList.add("puxcantidad");
      td_puxcantidad.id = "puxcantidad";
      td_puxcantidad.textContent = 0;
      var td_eliminar = document.createElement("td");
      var boton_eliminar = document.createElement("button");
      boton_eliminar.type = "button";
      boton_eliminar.classList.add("btn", "btn-danger", "rounded-pill", "eliminar-producto");
      boton_eliminar.id = "eliminar-producto";
      boton_eliminar.textContent = "Quitar";
      var select = document.createElement("select");
      select.name = "producto";
      select.id = "producto";
      select.classList.add("producto");
      var i = 1;
      for (producto of $productos) {
        var op = document.createElement("option");
        op.value = producto["id_producto"];
        op.id = "producto-" + i.toString();
        op.textContent = producto["nombre"];
        select.appendChild(op);
        i++;
      }
      td_nombre.appendChild(select);
      td_pu.textContent = ($productos[0]["precio"]);
      td_cantidad.appendChild(input_cantidad);
      td_eliminar.appendChild(boton_eliminar);
      tr.appendChild(td_nombre);
      tr.appendChild(td_pu);
      tr.appendChild(td_cantidad);
      tr.appendChild(td_puxcantidad);
      tr.appendChild(td_eliminar);
      fila_total.insertAdjacentElement("beforebegin", tr);
      function actualizarPuCantidad(e, pu, cantidad) {
        e.textContent = (parseFloat(pu) * parseInt(cantidad)).toString();
      }
      function actualizarTotal() {
        var s = 0;
        var pxc = document.getElementsByClassName("puxcantidad");
        puxcantidad = Array.prototype.slice.call(pxc);
        puxcantidad.forEach(function(e, i, a) {
          s += parseFloat(e.textContent);
        });
        var total_venta = document.getElementById("total").children[1];
        total_venta.textContent = s.toString();
      }
      $("select#producto").each(function() {
        $(this).change(function(e) {
          var elemento = e.target;
          var tr_raiz = elemento.parentElement.parentElement;
          var indice_producto = parseInt(((elemento.options[elemento.selectedIndex].id).split("-"))[1]) - 1;
          var precio_unitario = tr_raiz.children[1];
          precio_unitario.textContent = $productos[indice_producto]["precio"];
          actualizarPuCantidad(tr_raiz.children[3], $productos[indice_producto]["precio"], tr_raiz.children[2].children[0].value);
          actualizarTotal();
          tr_raiz = tr_raiz.parentElement;
          var total = document.getElementById("total");
        });
      });
      $("input#cantidad").each(function() {
        $(this).change(function(e) {
          var elemento = e.target;
          var tr_raiz = elemento.parentElement.parentElement;
          actualizarPuCantidad(tr_raiz.children[3], tr_raiz.children[1].textContent, elemento.value);
          actualizarTotal();
        });
      });
      $("button#eliminar-producto").each(function() {
        $(this).click(function(e) {
          var elemento = e.target;
          var tr_raiz = elemento.parentElement.parentElement;
          tr_raiz.remove();
          actualizarTotal();
        });
      });
    });
    $("button#enviar-datos").click(function(e) {
      var datos = {
        id_cliente: document.getElementById("cliente").value,
        fecha_venta: document.getElementById("fecha-venta").value,
        productos: [],
        total: parseFloat(document.getElementById("total").children[1].textContent)
      };
      var producto_venta = document.getElementsByClassName("producto-para-venta");
      var pv = Array.prototype.slice.call(producto_venta);
      pv.forEach(function(e, i, a) {
        datos["productos"].push({
          id_producto: e.children[0].children[0].value,
          cantidad: e.children[2].children[0].value
        });
      });
      $.ajax({
        url: $base_url + "ventas/crear",
        dataType: "json",
        type: "POST",
        contentType: 'application/json',
        data: JSON.stringify(datos),
        processData: false,
        success: function(data){
          if (data["estado"]) {
            var redirect_url = $base_url + "ventas";
            window.location.href = redirect_url;
          }
          else {
            alert("Ha ocurrido un error, por favor intente mas tarde...");
          }
        }
      });
    });
  });
})