# This Python file uses the following encoding: utf-8
import requests
from bs4 import BeautifulSoup

url = 'https://search.naver.com/search.naver'\
      '?where=nexearch&sm=top_hty&fbm=1&ie=utf8&query=%EB%82%A0%EC%94%A8'

response = requests.get(url)

if response.status_code == 200:
    html = response.text
    soup = BeautifulSoup(html, 'html.parser')
    title = soup.select_one('#main_pack > '
                            'section.sc_new.cs_weather_new._cs_weather >'
                            'div._tab_flicking > div.content_wrap > div.open >'
                            'div:nth-child(1) > div > div.weather_info > div >'
                            'div.temperature_info > p >'
                            'span.weather.before_slash')
    print(title)
else:
    print(response.status_code)
# if __name__ == "__main__":
#     pass
