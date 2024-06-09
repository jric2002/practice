import time
def my_decorator_name(name):
  def my_custome_decorator(function):
    def wrapper(*args, **kwargs):
      start = time.time()
      resultado = function(*args, **kwargs)
      end = time.time()
      print(f"Tiempo de ejecución de {function.__name__}: {end - start} segundos")
      