class Libro:
  def __init__(self, titulo, autor, anio, genero, isbn):
    if not anio.isdigit():
      raise ValueError("El año debe ser un número.")
    self.titulo = titulo
    self.autor = autor
    self.anio = anio
    self.genero = genero
    self.isbn = isbn
  def __str__(self):
    return f"{self.titulo}, {self.autor}, {self.anio}, {self.genero}, {self.isbn}"