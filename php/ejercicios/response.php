<?php
function response($practice, $response) {
  echo <<<RESPONSE
  <!DOCTYPE html>
  <html lang="en">
    <head>
      <meta charset="UTF-8">
      <meta http-equiv="X-UA-Compatible" content="IE=edge">
      <meta name="viewport" content="width=device-width, initial-scale=1.0">
      <title>{$practice}</title>
      <link rel="stylesheet" type="text/css" href="../response.css"/>
    </head>
    <body>
      <div class="response">
        <div>{$response}</div>
      </div>
    </body>
  </html>
  RESPONSE;
}
?>