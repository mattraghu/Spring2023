import { useContext } from "react";

import MeetUpList from "../components/meetups/MeetupList";
import { FavoritesContext } from "../store/favorites-context";
function FavoritesPage() {
	//  Return "No Meetups Found" if Length of Favorites is 0
	const favoritesCtx = useContext(FavoritesContext);

	if (favoritesCtx.favorites.length === 0) {
		return <p>You got no favorites yet. Start adding some.</p>;
	}

	return (
		<div>
			<h1>Favorites</h1>
			<MeetUpList favoritesOnly />
		</div>
	);
}

export default FavoritesPage;
