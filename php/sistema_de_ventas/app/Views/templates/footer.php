    <div class="container-fluid d-flex justify-content-center align-items-center bg-dark bg-opacity-75 text-white py-3 <?php if (in_array($page, ["clientes", "productos", "ventas", "detalles"])): echo "no-print"; endif; ?>">&copy; Sistema de ventas - 2022</div>
    <!-- Bootstrap Bundle with Popper -->
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-ka7Sk0Gln4gmtz2MlQnikT1wXgYsOg+OMhuP+IlRH9sENBO0LRn5q+8nbTov4+1p" crossorigin="anonymous"></script>
    <?php if (in_array($page, ["inicio"])): ?>
    <!-- Chart.js -->
    <script src="https://cdn.jsdelivr.net/npm/chart.js@3.8.0/dist/chart.min.js"></script>
    <?php endif; ?>
    <?php if (in_array($page, ["inicio", "clientes", "productos", "ventas", "detalles"])): ?>
    <!-- JQuery -->
    <script src="https://code.jquery.com/jquery-3.6.0.min.js" integrity="sha256-/xUj+3OJU5yExlq6GSYGSHk7tPXikynS7ogEvDej/m4=" crossorigin="anonymous"></script>
    <!-- DataTable - JavaScript -->
    <script type="text/javascript" charset="utf8" src="https://cdn.datatables.net/1.12.1/js/jquery.dataTables.js"></script>
    <!-- JavaScript Files -->
    <script type="text/javascript" src="/js/print.js"></script>
    <?php endif; ?>
    <?php if (in_array($page, ["inicio", "clientes", "productos", "ventas", "detalles"])): ?>
    <!-- JavaScript Files -->
    <script type="text/javascript" src="/js/<?php echo $page; ?>.js"></script>
    <?php endif; ?>
  </body>
</html>
