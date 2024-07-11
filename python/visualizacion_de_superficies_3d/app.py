import streamlit as st
from mods.superficie3d import Plano, Paraboloide, Sinusoide
from mods.visualizador import Visualizador3D

def main():
    st.set_page_config(
        page_title="Visualizador de Superficies 3D",
        page_icon="🎲"
    )
    st.title("Visualizador de Superficies 3D")

    tipo = st.selectbox("Seleccione el tipo de superficie:",
                        ["Plano", "Paraboloide", "Sinusoide"])

    x_range = st.slider("Rango de X:", -10.0, 10.0, (-5.0, 5.0))
    y_range = st.slider("Rango de Y:", -10.0, 10.0, (-5.0, 5.0))

    if tipo == "Plano":
        pendiente = st.number_input("Pendiente del plano:", -10.0, 10.0, 1.0)
        superficie = Plano(x_range, y_range, pendiente)
    elif tipo == "Paraboloide":
        coef = st.number_input("Coeficiente del paraboloide:", -10.0, 10.0, 1.0)
        superficie = Paraboloide(x_range, y_range, coef)
    elif tipo == "Sinusoide":
        frecuencia = st.number_input("Frecuencia de la sinusoide:", -10.0, 10.0, 1.0)
        superficie = Sinusoide(x_range, y_range, frecuencia)
    else:
        st.error("Opción no válida.")
        return

    visualizador = Visualizador3D(superficie)
    fig = visualizador.mostrar_con_plotly()

    st.plotly_chart(fig)

if __name__ == "__main__":
    main()
