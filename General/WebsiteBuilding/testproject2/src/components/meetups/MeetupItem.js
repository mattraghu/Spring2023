import { useContext } from "react";

import classes from "./MeetupItem.module.css";
import Card from "../UI/Card";

import { FavoritesContext } from "../../store/favorites-context";
function MeetupItem(props) {
	const meetup = props.meetup;

	const favoritesCtx = useContext(FavoritesContext);

	const itemIsFavorite = favoritesCtx.itemIsFavorite(meetup.id);
	function toggleFavoriteHandler() {
		if (itemIsFavorite) {
			favoritesCtx.removeFavorite(meetup.id);
		} else {
			favoritesCtx.addFavorite(meetup.id);
			console.log(favoritesCtx.favorites);
		}
	}

	// Return "No Meetups Found" if favoritesOnly and itemIsFavorite is falseA
	if (props.favoritesOnly && !itemIsFavorite) {
		return null;
	}
	return (
		<Card>
			<li className={classes.item}>
				{/* Image */}
				<div className={classes.image}>
					<img src={meetup.image} alt={meetup.title} />
				</div>
				{/* Content */}
				<div className={classes.content}>
					<h3>{meetup.title}</h3>
					<address>{meetup.address}</address>
					<p>{meetup.description}</p>
				</div>

				<div className={classes.actions}>
					{/* Button */}
					{/* Button Text = Favorite or Unfavorite Depending on Whether Button is Favorite*/}
					<button onClick={toggleFavoriteHandler}>
						{itemIsFavorite ? "Remove from Favorites" : "Add to Favorites"}
					</button>
				</div>
			</li>
		</Card>
	);
}

export default MeetupItem;
