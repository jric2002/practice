<?php
  namespace App\Models;
  use CodeIgniter\Model;
  class UserModel extends Model {
    public function obtenerDatos($nombre_tabla) {
      $tabla = $this->db->table($nombre_tabla);
      return $tabla->get()->getResultArray();
    }
    public function insertar($datos, $nombre_tabla) {
      $tabla = $this->db->table($nombre_tabla);
      $tabla->insert($datos);
      return $this->db->insertID();
    }
    public function actualizar($name_column, $id, $datos, $nombre_tabla) {
      $tabla = $this->db->table($nombre_tabla);
      $tabla->where($name_column, $id)->set($datos)->update();
    }
    public function eliminar($name_column, $id, $nombre_tabla) {
      $tabla = $this->db->table($nombre_tabla);
      $tabla->where($name_column, (int)$id)->delete();
    }
    public function unirTablas($tabla_1, $id_t1, $tabla_2, $id_t2) {
      $tabla = $this->db->table($tabla_1);
      $tabla->join($tabla_2, "${id_t2} = ${id_t1}");
      return $tabla->get()->getResultArray();
    }
    public function obtenerTotalClientes() {
      $datos = $this->db->query("SELECT COUNT(*) AS cantidad_clientes FROM clientes");
      return $datos->getResultArray();
    }
    public function obtenerTotalVentas() {
      $datos = $this->db->query("SELECT COUNT(*) AS cantidad_ventas FROM ventas");
      return $datos->getResultArray();
    }
    public function obtenerTotalProductos() {
      $datos = $this->db->query("SELECT COUNT(*) AS cantidad_productos FROM productos");
      return $datos->getResultArray();
    }
    public function obtenerVentasPorDia() {
      $datos = $this->db->query("SELECT COUNT(*) AS cantidad_ventas, fecha_venta FROM ventas GROUP BY fecha_venta");
      return $datos->getResultArray();
    }
    public function obtenerClientesPorVentas() {
      $datos = $this->db->query("SELECT clientes.nombres, clientes.apellidos, SUM(ventas.venta_total) AS venta_total FROM ventas INNER JOIN clientes ON clientes.id_cliente = ventas.id_cliente GROUP BY ventas.id_cliente");
      return $datos->getResultArray();
    }
    public function obtenerNombreDeImagen($id) {
      $datos = $this->db->query("SELECT imagen FROM productos WHERE id_producto = ".$id);
      return $datos->getResultArray();
    }
    public function insertarVenta($id_cliente, $fecha_venta, $venta_total) {
      $id_cliente = intval($id_cliente);
      $venta_total = floatval($venta_total);
      $this->db->query("INSERT INTO ventas (id_cliente, fecha_venta, fecha_registro_venta, venta_total) VALUES (".$id_cliente.", '".$fecha_venta."', NOW(), ".$venta_total.")");
      return $this->db->insertID();
    }
    public function obtenerDetalles() {
      $datos = $this->db->query("SELECT d.id_detalle, d.id_venta, v.fecha_venta, v.fecha_registro_venta, CONCAT(c.nombres, ' ', c.apellidos) AS cliente, p.nombre AS producto, p.precio, d.cantidad FROM detalles d JOIN productos p ON p.id_producto = d.id_producto JOIN ventas v ON d.id_venta = v.id_venta JOIN clientes c ON v.id_cliente = c.id_cliente ORDER BY d.id_venta ASC;");
      return $datos->getResultArray();
    }
  }
?>