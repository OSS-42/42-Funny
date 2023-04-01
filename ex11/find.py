import	requests

def get_pokemon_abilities(pokemon_name):
	url = f'https://pokeapi.co/api/v2/pokemon/{pokemon_name.lower()}'
	response = requests.get(url)
	
	if response.status_code == 200:
		data = response.json()
		abilities = [ability['ability']['name'] for ability in data['abilities']]
		return abilities
	else:
		return None

def main():
	pokemon_name = input('Enter the name of the Pokemon: ')
	abilities = get_pokemon_abilities(pokemon_name)

	if abilities:
		print(f"\nAbilities of {pokemon_name.capitalize()}:")
		for ability in abilities:
			print(f"- {ability}")
	else:
		print(f"\nPokemon '{pokemon_name}' not found. Please check the spelling and try again.")

if __name__ == "__main__":
	main()
