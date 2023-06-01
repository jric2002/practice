<?php

namespace App\Controllers;
use App\Models\UserModel;
class Ventas extends BaseController
{
    public function index()
    {
        $user_model = new UserModel();
        $datos = $user_model->unirTablas("ventas", "ventas.id_cliente", "clientes", "clientes.id_cliente");
        $data = [
            "head" => [
                "title" => "Ventas - Sistema de ventas",
                "description" => "Página de ventas - Sistema de ventas"
            ],
            "page" => "ventas",
            "datos" => $datos
        ];
        return view("templates/header", $data).
                view("ventas/ventas").
                view("templates/footer", ["page" => $data["page"]]);
    }
    public function crear() {
        $user_model = new UserModel();
        $data = json_decode(file_get_contents('php://input'), TRUE);
        $id_venta = $user_model->insertarVenta($data["id_cliente"], $data["fecha_venta"], $data["total"]);
        foreach ($data["productos"] as $venta_producto) {
            $datos = [
                "id_venta" => intval($id_venta),
                "id_producto" => intval($venta_producto["id_producto"]),
                "cantidad" => intval($venta_producto["cantidad"])
            ];
            $user_model->insertar($datos, "detalles");
        }
        return json_encode(["estado" => TRUE]);
    }
    public function reportePdf() {
        $user_model = new UserModel();
        $datos = $user_model->unirTablas("ventas", "ventas.id_venta", "clientes", "clientes.id_cliente");
        $data = [
            "datos" => $datos
        ];
        $this->response->setHeader("Content-Type", "application/pdf");
        return view("ventas/reporte-ventas-pdf", $data);
    }
    public function reporteXls() {
        $user_model = new UserModel();
        $datos = $user_model->unirTablas("ventas", "ventas.id_venta", "clientes", "clientes.id_cliente");
        $data = [
            "datos" => $datos
        ];
        return view("ventas/reporte-ventas-xls", $data);
    }
    public function obtenerClientes() {
        $user_model = new UserModel();
        $datos = $user_model->obtenerDatos("clientes");
        return json_encode($datos);
    }
    public function obtenerProductos() {
        $user_model = new UserModel();
        $datos = $user_model->obtenerDatos("productos");
        return json_encode($datos);
    }
}