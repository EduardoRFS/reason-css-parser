open Standard;
open Combinator;
open Modifier;
open Rule.Match;
// TODO: split by modules

let property_width = [%value "auto"];

let property_flex_direction = [%value
  "row | row-reverse | column | column-reverse"
];
let property_flex_wrap = [%value "nowrap | wrap | wrap-reverse"];
let property_flex_flow = [%value "<'flex-direction'> || <'flex-wrap'>"];
let property_order = [%value "<integer>"];
let property_flex_grow = [%value "<number>"];
let property_flex_shrink = [%value "<number>"];
let property_flex_basis = [%value "content | <'width'>"];
let property_flex = [%value
  "none | [ <'flex-grow'> <'flex-shrink'>? || <'flex-basis'> ]"
];
let property_justify_content = [%value
  "flex-start | flex-end | center | space-between | space-around"
];
let property_align_items = [%value
  "flex-start | flex-end | center | baseline | stretch"
];
let property_align_self = [%value
  "auto | flex-start | flex-end | center | baseline | stretch"
];
let property_align_content = [%value
  "flex-start | flex-end | center | space-between | space-around | stretch"
];

let parse = (prop, str) => {
  let (output, tokens) =
    Sedlexing.Utf8.from_string(str) |> Lexer.read_all |> prop;

  let matched_everything =
    switch (tokens) {
    | [] => Ok()
    | _ => Error("tokens remaining")
    };
  Result.bind(matched_everything, () => output);
};
