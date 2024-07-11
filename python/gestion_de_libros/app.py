import streamlit as st
import pandas as pd
from mods.libro import Libro
from mods.inventario import Inventario

def main():
  st.set_page_config(
    page_title="Gestión de Libros",
    page_icon="📚"
  )
  # Configurar el inventario con el archivo CSV
  archivo_csv = 'inventario_libros.csv'
  inventario = Inventario(archivo_csv)
  # Configurar la aplicación Streamlit
  st.title("Gestión de Libros 📚")
  # Definir las opciones como pestañas
  tabs = st.tabs(["Agregar Libro", "Eliminar Libro", "Buscar Libro", "Listar Libros", "Actualizar Libro", "Descargar CSV"])
  # Pestaña para agregar un libro
  with tabs[0]:
    st.header("Agregar Nuevo Libro")
    with st.form(key='agregar_libro_form'):
      titulo = st.text_input("Título")
      autor = st.text_input("Autor")
      anio = st.text_input("Año")
      genero = st.text_input("Género")
      isbn = st.text_input("ISBN")
      if st.form_submit_button("Agregar Libro"):
        try:
          if not anio.isdigit():
            raise ValueError("El año debe ser un número.")
          libro = Libro(titulo, autor, anio, genero, isbn)
          inventario.agregar_libro(libro)
          st.success("Libro agregado exitosamente.")
        except ValueError as e:
          st.error(f"Error al agregar libro: {e}")
  # Pestaña para eliminar un libro
  with tabs[1]:
    st.header("Eliminar Libro")
    with st.form(key='eliminar_libro_form'):
      titulo_eliminar = st.text_input("Título del libro")
      if st.form_submit_button("Eliminar Libro"):
        try:
          libro_encontrado = inventario.buscar_libro(titulo_eliminar)
          if libro_encontrado:
            inventario.eliminar_libro(libro_encontrado.titulo)
            st.success("Libro eliminado exitosamente.")
          else:
            st.error("El libro con este título no se encuentra en el inventario.")
        except ValueError as e:
          st.error(f"Error al eliminar libro: {e}")
  # Pestaña para buscar un libro
  with tabs[2]:
    st.header("Buscar Libro")
    with st.form(key='buscar_libro_form'):
      titulo_buscar = st.text_input("Título del libro")
      if st.form_submit_button("Buscar Libro"):
        libro = inventario.buscar_libro(titulo_buscar)
        if libro:
          st.write("Libro encontrado:", libro)
        else:
          st.write("Libro no encontrado.")
  # Pestaña para listar todos los libros
  with tabs[3]:
    st.header("Listado de Libros")
    libros = [libro for libro in inventario.libros.values()]
    if libros:
      for libro in libros:
        st.write(libro)
    else:
      st.write("No hay libros en el inventario.")
  # Pestaña para actualizar un libro
  with tabs[4]:
    st.header("Actualizar Libro")
    with st.form(key='actualizar_libro_form'):
      titulo_actualizar = st.text_input("Título del libro")
      if st.form_submit_button("Buscar Libro"):
        libro = inventario.buscar_libro(titulo_actualizar)
        if libro:
          nuevo_titulo = st.text_input("Nuevo título", value=libro.titulo)
          nuevo_autor = st.text_input("Nuevo autor", value=libro.autor)
          nuevo_anio = st.text_input("Nuevo año", value=libro.anio)
          nuevo_genero = st.text_input("Nuevo género", value=libro.genero)
          # Mostrar un mensaje de confirmación antes de actualizar
          if st.form_submit_button("Actualizar Libro"):
            try:
              kwargs = {}
              if nuevo_titulo != libro.titulo:
                kwargs['titulo'] = nuevo_titulo
              if nuevo_autor != libro.autor:
                kwargs['autor'] = nuevo_autor
              if nuevo_anio != libro.anio:
                if not nuevo_anio.isdigit():
                  raise ValueError("El año debe ser un número.")
                kwargs['anio'] = nuevo_anio
              if nuevo_genero != libro.genero:
                kwargs['genero'] = nuevo_genero
              inventario.actualizar_libro(titulo_actualizar, **kwargs)
              inventario.guardar_libros()  # Guardar cambios en el archivo CSV
              st.success("Libro actualizado exitosamente.")
            except ValueError as e:
              st.error(f"Error al actualizar libro: {e}")
        else:
          st.error("El libro con este título no se encuentra en el inventario.")
  # Pestaña para descargar el inventario como CSV
  with tabs[5]:
    st.header("Descargar Inventario como CSV")
    if st.button("Descargar CSV"):
      inventario.guardar_libros()
      st.success("Inventario guardado como CSV correctamente.")

if __name__ == "__main__":
  main()