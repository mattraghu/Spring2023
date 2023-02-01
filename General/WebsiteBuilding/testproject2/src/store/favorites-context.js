// Controller for Managing Favorites
import { createContext, useState } from "react";

const FavoritesContext = createContext({
	favorites: [],
	addFavorite: (favoriteMeetup) => {},
	removeFavorite: (meetupId) => {},
	itemIsFavorite: (meetupId) => {},
});

function FavoritesContextProvider(props) {
	const [favorites, setFavorites] = useState([]);

	function addFavoriteHandler(meetupId) {
		setFavorites((prevFavorites) => {
			//Add meetupId to prevFavorites
			//We can use the spread operator to add the meetupId to the prevFavorites array
			return prevFavorites.concat([meetupId]);
		});
	}

	function removeFavoriteHandler(meetupId) {
		setFavorites((prevFavorites) => {
			return prevFavorites.filter((prevFavId) => prevFavId !== meetupId);
		});
	}

	function itemIsFavoriteHandler(meetupId) {
		console.log(favorites);
		return favorites.includes(meetupId);
	}

	const context = {
		favorites: favorites,
		addFavorite: addFavoriteHandler,
		removeFavorite: removeFavoriteHandler,
		itemIsFavorite: itemIsFavoriteHandler,
	};

	return (
		<FavoritesContext.Provider value={context}>
			{props.children}
		</FavoritesContext.Provider>
	);
}

export { FavoritesContextProvider, FavoritesContext };
