<?php

namespace App\Controllers;
use App\Models\UserModel;
class Detalles extends BaseController
{
    public function index()
    {
        $user_model = new UserModel();
        $detalles = $user_model->obtenerDetalles();
        $data = [
            "head" => [
                "title" => "Detalles - Sistema de ventas",
                "description" => "Página de detalles - Sistema de ventas"
            ],
            "page" => "detalles",
            "detalles" => $detalles
        ];
        return view("templates/header", $data).
                view("detalles/detalles", ["datos" => $data["detalles"]]).
                view("templates/footer", ["page" => $data["page"]]);
    }
    public function reportePdf() {
        $user_model = new UserModel();
        $datos = $user_model->obtenerDetalles();
        $data = [
            "datos" => $datos
        ];
        $this->response->setHeader("Content-Type", "application/pdf");
        return view("detalles/reporte-detalles-pdf", $data);
    }
    public function reporteXls() {
        $user_model = new UserModel();
        $datos = $user_model->obtenerDetalles();
        $data = [
            "datos" => $datos
        ];
        return view("detalles/reporte-detalles-xls", $data);
    }
}