<?php

namespace App\Controllers;

class AcercaDe extends BaseController
{
    public function index()
    {
        $data = [
            "head" => [
                "title" => "Acerca de - Sistema de ventas",
                "description" => "Página de Acerca de - Sistema de ventas"
            ],
            "page" => "acerca_de"
        ];
        return view("templates/header", $data).
                view("acerca_de/acerca_de").
                view("templates/footer", ["page" => $data["page"]]);
    }
}