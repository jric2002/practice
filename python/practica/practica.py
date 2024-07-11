import streamlit as st
class Persona:
  def __init__(self, nombre, edad, genero):
    self.name = nombre
    self.age = edad
    self.genre = genero

lista = {
  "jos": Persona("jos", 23, "m"),
  "juan": Persona("juan", 23, "a"),
  "maria": Persona("maria", 24, "f")
}
st.title("hola")
tabs = st.tabs(["agregar", "modifcar", "ver"])
with tabs[0]:
  with st.form(key='agregar'):
    name = st.text_input("nombre")
    age = st.text_input("edad")
    genre = st.text_input("genero")
    if st.form_submit_button("agregar"):
      lista[name] = Persona(name, age, genre)
      st.success("agregado")
with tabs[1]:
  exists = False
  person = None
  with st.form(key='modificar'):
    name = st.text_input("nombre")
    if st.form_submit_button("buscar"):
      if name in lista.keys():
        person = lista[name]
        exists = True
      else:
        exists = None
  if exists:
    with st.container():
      with st.form('editar datos'):
        name = st.text_input("nombre", value=person.name)
        age = st.text_input("edad", value=person.age)
        genre = st.text_input("genero", value=person.genre)
        if st.form_submit_button("actualizar"):
          try:
            person.name = name
            person.age = age
            person.genre = genre
            st.success("datos actualizados")
          except Exception as e:
            st.error(f"hubo un error al actualizar sus datos: {e}")
  elif (exists == None):
    st.error("no existe esa persona")
with tabs[2]:
  for p in lista.values():
    st.write(f"{p.name} - {p.age}")