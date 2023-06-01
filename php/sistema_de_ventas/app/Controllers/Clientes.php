<?php
namespace App\Controllers;
use App\Models\UserModel;
class Clientes extends BaseController
{
    public function index()
    {
        $user_model = new UserModel();
        $clientes = $user_model->obtenerDatos("clientes");
        $data = [
            "head" => [
                "title" => "Clientes - Sistema de ventas",
                "description" => "Página de clientes - Sistema de ventas"
            ],
            "page" => "clientes",
            "clientes" => $clientes
        ];
        return view("templates/header", $data).
                view("clientes/clientes", ["clientes" => $data["clientes"]]).
                view("templates/footer", ["page" => $data["page"]]);
    }
    public function crear() {
        $datos = [
            "nombres" => $_POST["nombres"],
            "apellidos" => $_POST["apellidos"],
            "direccion" => $_POST["direccion"]
        ];
        $user_model = new UserModel();
        $respuesta = $user_model->insertar($datos, "clientes");
        return redirect()->to(base_url()."/clientes");
    }
    public function actualizar($id_cliente) {
        $data = [
            "nombres" => $_POST["nombres"],
            "apellidos" => $_POST["apellidos"],
            "direccion" => $_POST["direccion"]
        ];
        $user_model = new UserModel();
        $user_model->actualizar("id_cliente", $id_cliente, $data, "clientes");
        return redirect()->to(base_url()."/clientes");
    }
    public function eliminar($id_cliente) {
        $user_model = new UserModel();
        $user_model->eliminar("id_cliente", $id_cliente, "clientes");
        return redirect()->to(base_url()."/clientes");
    }
    public function reportePdf() {
        $user_model = new UserModel();
        $clientes = $user_model->obtenerDatos("clientes");
        $data = [
            "clientes" => $clientes
        ];
        $this->response->setHeader("Content-Type", "application/pdf");
        return view("clientes/reporte-clientes-pdf", $data);
    }
    public function reporteXls() {
        $user_model = new UserModel();
        $clientes = $user_model->obtenerDatos("clientes");
        $data = [
            "clientes" => $clientes
        ];
        return view("clientes/reporte-clientes-xls", $data);
    }
}