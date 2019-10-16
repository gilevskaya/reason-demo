[@react.component]
let make = () => {
  let (count, setCount) = React.useState(() => 0);

  <div style={ReactDOMRe.Style.make(~display="flex", ())}>
    <button
      style={ReactDOMRe.Style.make(
        ~outline="none",
        ~backgroundColor="mediumpurple",
        ~borderRadius="3px",
        ~paddingLeft="7px",
        ~paddingRight="7px",
        ~marginRight="14px",
        ~fontWeight="600",
        (),
      )}
      onClick={_ => setCount(_ => count + 1)}>
      {ReasonReact.string("+")}
    </button>
    <div> {ReasonReact.string("clicked: " ++ string_of_int(count))} </div>
  </div>;
};