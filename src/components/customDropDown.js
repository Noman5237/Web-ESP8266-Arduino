import { serverIP } from "../App.js";
import React from "react";
import InputLabel from "@material-ui/core/InputLabel";
import FormControl from "@material-ui/core/FormControl";
import Select from "@material-ui/core/Select";
const axios = require("axios").default;

export default function NativeSelects({ pin }) {
  const [state, setState] = React.useState({
    pin: pin,
    data: "1",
  });

  const handleChange = (event) => {
    setState({
      ...state,
      data: event.target.value,
    });
    axios
      .get(`http://${serverIP}/data?mode=d&pin=${pin}&data=${state.data}`)
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

  return (
    <FormControl>
      <InputLabel>Pin: {pin}</InputLabel>
      <Select
        native
        value={state.data}
        onChange={handleChange}
        inputProps={{
          name: "pin",
          id: "pin-native-simple",
        }}
      >
        <option value={"0"}>HIGH</option>
        <option value={"1"}>LOW</option>
      </Select>
    </FormControl>
  );
}
