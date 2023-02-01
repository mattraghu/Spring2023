import { useState, useEffect } from "react";

import MeetupItem from "./MeetupItem";

function MeetUpList(props) {
	const [dataLoaded, setDataLoaded] = useState(false);

	/* Convert meetups data to a list of <li> elements */
	// Fetch The Data From The Database
	useEffect(() => {
		fetch("https://testproject2-3faef-default-rtdb.firebaseio.com/meetups.json")
			.then((response) => {
				return response.json();
			})
			.then((data) => {
				//Convert the data to an array to use map function
				data = Object.values(data);

				//Add the id to each meetup object
				data = data.map((meetup, index) => {
					meetup.id = index + 1;
					return meetup;
				});

				//Set the dataLoaded state to true
				setDataLoaded(data);
			});
	}, []);

	return (
		<ul>
			{/* Load Meetups when data is loaded else show loading message */}
			{!dataLoaded && <p>Loading...</p>}
			{dataLoaded &&
				// meetups.map((meetup) => <MeetupItAem key={meetup.id} meetup={meetup} />)}
				dataLoaded.map((meetup) => {
					return (
						<MeetupItem
							key={meetup.id}
							meetup={meetup}
							favoritesOnly={props.favoritesOnly}
						/>
					);
				})}

			{/* {meetups.map((meetup) => {
				console.log(meetup);
				return <MeetupItem key={meetup.id} meetup={meetup} />;
			})} */}
		</ul>
	);
}

export default MeetUpList;
