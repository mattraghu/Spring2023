import DUMMY_DATA from "../components/dummy_data";

import MeetUpList from "../components/meetups/MeetupList";

function AllMeetupsPage() {
	return (
		<div>
			<h1>All Meetups Page</h1>
			<MeetUpList meetups={DUMMY_DATA} />


			
		</div>
	);
}

export default AllMeetupsPage;
