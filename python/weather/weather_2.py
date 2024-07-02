import requests
import csv

class Weather:
  def __init__(self, api_key):
    self.api_key = api_key
    self.base_url = "http://api.openweathermap.org/data/2.5/weather?"

  def get_weather_by_city(self, city_name):
    complete_url = f"{self.base_url}q={city_name}&appid={self.api_key}"
    response = requests.get(complete_url)
    if response.status_code == 200:
      return response.json()
    else:
      return {"cod": "404"}

  def save_to_csv(self, weather_data, filename):
    if weather_data["cod"] != "404":
      main = weather_data["main"]
      wind = weather_data["wind"]
      weather_desc = weather_data["weather"][0]["description"]
      with open(filename, mode='w', newline='') as file:
        writer = csv.writer(file)
        writer.writerow(['City', 'Temperature (K)', 'Humidity (%)', 'Pressure (hPa)', 'Weather Description', 'Wind Speed (m/s)'])
        writer.writerow([
          weather_data["name"],
          main['temp'],
          main['humidity'],
          main['pressure'],
          weather_desc,
          wind['speed']
        ])
      print(f"Weather data saved to {filename}")
    else:
      print("Cannot save data for this city as it was not found.")

# Ejemplo de uso para guardar datos en CSV
weather_instance = Weather("your_api_key")
weather_data = weather_instance.get_weather_by_city("London")
weather_instance.save_to_csv(weather_data, "weather_data.csv")