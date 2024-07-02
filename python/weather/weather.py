import requests

class Weather:
  def __init__(self, api_key):
    self.api_key = api_key
    self.base_url = "http://api.openweathermap.org/data/2.5/weather?"

  def get_weather_by_city(self, city_name):
    complete_url = f"{self.base_url}q={city_name}&appid={self.api_key}"
    response = requests.get(complete_url)
    return response.json()

  def get_weather_by_coordinates(self, lat, lon):
    complete_url = f"{self.base_url}lat={lat}&lon={lon}&appid={self.api_key}"
    response = requests.get(complete_url)
    return response.json()

  def display_weather(self, weather_data):
    if weather_data["cod"] != "404":
      main = weather_data["main"]
      wind = weather_data["wind"]
      weather_desc = weather_data["weather"][0]["description"]
      print(f"Temperature: {main['temp']}K")
      print(f"Humidity: {main['humidity']}%")
      print(f"Pressure: {main['pressure']}hPa")
      print(f"Weather Description: {weather_desc}")
      print(f"Wind Speed: {wind['speed']} m/s")
    else:
      print("City Not Found!")

# Reemplaza 'your_api_key_here' con tu clave API de OpenWeatherMap
weather = Weather('api_key')

# Obtener datos meteorológicos para una ciudad específica
city_name = "London"
city_weather = weather.get_weather_by_city(city_name)
print(city_weather, "\n")

# Obtener datos meteorológicos para coordenadas específicas
latitude = 51.5074
longitude = -0.1278
coord_weather = weather.get_weather_by_coordinates(latitude, longitude)
print(coord_weather, "\n")

city_name = "London"
city_weather = weather.get_weather_by_city(city_name)
weather.display_weather(city_weather)