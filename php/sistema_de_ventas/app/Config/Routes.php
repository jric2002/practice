<?php

namespace Config;

// Create a new instance of our RouteCollection class.
$routes = Services::routes();

// Load the system's routing file first, so that the app and ENVIRONMENT
// can override as needed.
if (is_file(SYSTEMPATH . 'Config/Routes.php')) {
    require SYSTEMPATH . 'Config/Routes.php';
}

/*
 * --------------------------------------------------------------------
 * Router Setup
 * --------------------------------------------------------------------
 */
$routes->setDefaultNamespace('App\Controllers');
$routes->setDefaultController('Inicio');
$routes->setDefaultMethod('index');
$routes->setTranslateURIDashes(false);
$routes->set404Override();
// The Auto Routing (Legacy) is very dangerous. It is easy to create vulnerable apps
// where controller filters or CSRF protection are bypassed.
// If you don't want to define all routes, please use the Auto Routing (Improved).
// Set `$autoRoutesImproved` to true in `app/Config/Feature.php` and set the following to true.
//$routes->setAutoRoute(false);

/*
 * --------------------------------------------------------------------
 * Route Definitions
 * --------------------------------------------------------------------
 */

// We get a performance increase by specifying the default
// route since we don't have to scan directories.
$routes->get('/', 'Inicio::index');
$routes->get('/ventas-por-dia', 'Inicio::obtenerVentasPorDia');
$routes->get('/clientes-por-ventas', 'Inicio::obtenerClientesPorVentas');
$routes->get("/clientes", "Clientes::index");
$routes->post("/clientes/crear", "Clientes::crear");
$routes->post("/clientes/actualizar/(:any)", "Clientes::actualizar/$1");
$routes->get("/clientes/eliminar/(:any)", "Clientes::eliminar/$1");
$routes->get("/clientes/reporte-clientes-pdf", "Clientes::reportePdf");
$routes->get("/clientes/reporte-clientes-xls", "Clientes::reporteXls");
$routes->get("/productos", "Productos::index");
$routes->post("/productos/crear", "Productos::crear");
$routes->post("/productos/actualizar/(:any)", "Productos::actualizar/$1");
$routes->get("/productos/eliminar/(:any)", "Productos::eliminar/$1");
$routes->get("/productos/reporte-productos-pdf", "Productos::reportePdf");
$routes->get("/productos/reporte-productos-xls", "Productos::reporteXls");
$routes->get("/ventas", "Ventas::index");
$routes->post("/ventas/crear", "Ventas::crear");
$routes->get("/ventas/obtener-clientes", "Ventas::obtenerClientes");
$routes->get("/ventas/obtener-productos", "Ventas::obtenerProductos");
$routes->get("/ventas/reporte-ventas-pdf", "Ventas::reportePdf");
$routes->get("/ventas/reporte-ventas-xls", "Ventas::reporteXls");
$routes->get("/detalles", "Detalles::index");
$routes->get("/detalles/reporte-detalles-pdf", "Detalles::reportePdf");
$routes->get("/detalles/reporte-detalles-xls", "Detalles::reporteXls");
$routes->get("/acerca_de", "AcercaDe::index");
/*
 * --------------------------------------------------------------------
 * Additional Routing
 * --------------------------------------------------------------------
 *
 * There will often be times that you need additional routing and you
 * need it to be able to override any defaults in this file. Environment
 * based routes is one such time. require() additional route files here
 * to make that happen.
 *
 * You will have access to the $routes object within that file without
 * needing to reload it.
 */
if (is_file(APPPATH . 'Config/' . ENVIRONMENT . '/Routes.php')) {
    require APPPATH . 'Config/' . ENVIRONMENT . '/Routes.php';
}