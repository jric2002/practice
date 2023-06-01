<?php

namespace App\Controllers;
use App\Models\UserModel;
class Inicio extends BaseController
{
    public function index()
    {
        $user_model = new UserModel();
        $datos = array();
        array_push($datos, ($user_model->obtenerTotalClientes())[0]);
        array_push($datos, ($user_model->obtenerTotalVentas())[0]);
        array_push($datos, ($user_model->obtenerTotalProductos())[0]);
        $data = [
            "head" => [
                "title" => "Sistema de ventas",
                "description" => "Página de inicio - Sistema de ventas"
            ],
            "page" => "inicio",
            "datos" => $datos
        ];
        return view("templates/header", $data).
                view("index", ["datos" => $data["datos"]]).
                view("templates/footer", ["page" => $data["page"]]);
    }
    public function obtenerClientesPorVentas() {
        $user_model = new UserModel();
        $datos = $user_model->obtenerClientesPorVentas();
        return json_encode($datos);
    }
    public function obtenerVentasPorDia() {
        $user_model = new UserModel();
        $datos = $user_model->obtenerVentasPorDia();
        return json_encode($datos);
    }
}