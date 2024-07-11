import pandas as pd
from mods.libro import Libro

class Inventario:
  def __init__(self, archivo_csv):
    self.libros = {}
    self.archivo_csv = archivo_csv
    self.cargar_libros()
  def cargar_libros(self):
    try:
      datos = pd.read_csv(self.archivo_csv)
      for _, fila in datos.iterrows():
        libro = Libro(fila['titulo'], fila['autor'], str(fila['anio']), fila['genero'], fila['isbn'])
        self.agregar_libro(libro)
    except FileNotFoundError:
      raise ValueError("Archivo no encontrado.")
  def guardar_libros(self):
    datos = []
    for libro in self.libros.values():
      datos.append({
        'titulo': libro.titulo,
        'autor': libro.autor,
        'anio': libro.anio,
        'genero': libro.genero,
        'isbn': libro.isbn
      })
    df = pd.DataFrame(datos)
    df.to_csv(self.archivo_csv, index=False)
  def agregar_libro(self, libro):
    if libro.isbn in self.libros:
      raise ValueError("El libro con este ISBN ya existe.")
    self.libros[libro.isbn] = libro
    self.guardar_libros()
  def eliminar_libro(self, isbn_eliminar):
    for isbn, libro in self.libros.items():
      if str(isbn) == str(isbn_eliminar):
        del self.libros[isbn]
        self.guardar_libros()
        return
    raise ValueError("El libro con este ISBN no se encuentra en el inventario.")
  def buscar_libro(self, texto, t="titulo"):
    if (t == "titulo"):
      for libro in self.libros.values():
        if libro.titulo.lower() == texto.lower():
          return libro
      return None
    elif (t == "isbn"):
      for libro_isbn in self.libros.keys():
        if str(libro_isbn) == str(texto):
          return self.libros[libro_isbn]
      return None
  def listar_libros(self):
    if not self.libros:
      print("No hay libros en el inventario.")
    else:
      for libro in self.libros.values():
        print(libro)
  def actualizar_libro(self, libro_isbn, **input):
    libro = self.buscar_libro(libro_isbn, t="isbn")
    if libro:
      for key, value in input.items():
        if hasattr(libro, key):
          setattr(libro, key, value)
      self.guardar_libros()
    else:
      raise ValueError("El libro con este ISBN no se encuentra en el inventario.")