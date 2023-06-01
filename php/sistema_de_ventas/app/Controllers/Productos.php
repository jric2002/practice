<?php

namespace App\Controllers;
use App\Models\UserModel;
class Productos extends BaseController
{
    public function index()
    {
        $user_model = new UserModel();
        $productos = $user_model->obtenerDatos("productos");
        $data = [
            "head" => [
                "title" => "Productos - Sistema de ventas",
                "description" => "Página de Productos - Sistema de ventas"
            ],
            "page" => "productos",
            "productos" => $productos
        ];
        return view("templates/header", $data).
                view("productos/productos").
                view("templates/footer", ["page" => $data["page"]]);
    }
    public function crear() {
        $dt = date('Y-m-d H:i:s:ms');
        $cadena_separada = explode(".", $_FILES["imagen"]["name"]);
        $extension = end($cadena_separada);
        $name = "img_".hash("md5", $dt).".".$extension;
        $datos["imagen"] = $name;
        $ruta = './images/'.$name;
        move_uploaded_file($_FILES["imagen"]["tmp_name"], $ruta);
        $datos = [
            "nombre" => $_POST["nombre"],
            "precio" => $_POST["precio"],
            "imagen" => $name
        ];
        $user_model = new UserModel();
        $respuesta = $user_model->insertar($datos, "productos");
        return redirect()->to(base_url()."/productos");
    }
    public function actualizar($id_producto) {
        $user_model = new UserModel();
        $datos = [
            "nombre" => $_POST["nombre"],
            "precio" => $_POST["precio"]
        ];
        if ($_FILES["imagen"]["size"] != 0) {
            // Delete image
            $nombre_imagen = ($user_model->obtenerNombreDeImagen($id_producto))[0]["imagen"];
            $archivo = './images/'.$nombre_imagen;
            if (file_exists($archivo) && is_writable($archivo)) {
                //unlink($archivo);
            }
            // Save image
            $dt = date('Y-m-d H:i:s:ms');
            $cadena_separada = explode(".", $_FILES["imagen"]["name"]);
            $extension = end($cadena_separada);
            $name = "img_".hash("md5", $dt).".".$extension;
            $datos["imagen"] = $name;
            $ruta = './images/'.$name;
            move_uploaded_file($_FILES["imagen"]["tmp_name"], $ruta);
        }
        $user_model->actualizar("id_producto", $id_producto, $datos, "productos");
        return redirect()->to(base_url()."/productos");
    }
    public function eliminar($id_producto) {
        $user_model = new UserModel();
        $user_model->eliminar("id_producto", $id_producto, "productos");
        return redirect()->to(base_url()."/productos");
    }
    public function reportePdf() {
        $user_model = new UserModel();
        $datos = $user_model->obtenerDatos("productos");
        $data = [
            "datos" => $datos
        ];
        $this->response->setHeader("Content-Type", "application/pdf");
        return view("productos/reporte-productos-pdf", $data);
    }
    public function reporteXls() {
        $user_model = new UserModel();
        $datos= $user_model->obtenerDatos("productos");
        $data = [
            "datos" => $datos
        ];
        return view("productos/reporte-productos-xls", $data);
    }
}