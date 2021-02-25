import React from "react";
import Slider from "@material-ui/core/Slider";
const axios = require("axios").default;

export default function ContinuousSlider({ pin }) {
  const [value, setValue] = React.useState(30);

  const handleChange = (event, newValue) => {
    setValue(newValue);
    axios
      .get(`http://192.168.0.104/data?mode=a&pin=${pin}&data=${newValue * 10}`)
      .then(function (response) {
        // handle success
        console.log(response);
      })
      .catch(function (error) {
        // handle error
        console.log(error);
      })
      .then(function () {
        // always executed
      });
  };

  return <Slider value={value} onChange={handleChange} max={25} />;
}
