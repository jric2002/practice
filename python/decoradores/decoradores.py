import time
def measureTime(function):
  def wrapper(*args, **kwargs):
    print("Antes de llamar a la función")
    start = time.time()
    result = function(*args, **kwargs)
    end = time.time()
    print("Después de llamar a la función")
    print(f"Tiempo de ejecución de {function.__name__}: {(end - start):.5f} segundos")
    return result
  return wrapper
@measureTime
def factorial(n):
  if n <= 1:
    return 1
  else:
    f = 1
    while n > 1:
      f *= n
      n -= 1
    return f
print(factorial(5))