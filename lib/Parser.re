open Standard;
open Combinator;
open Modifier;
open Rule.Match;
open Parser_helper;

let rec absolute_size = [%value.rec
  "'xx-small' | 'x-small' | 'small' | 'medium' | 'large' | 'x-large' | 'xx-large' | 'xxx-large'"
]
and alpha_value = [%value.rec "<number> | <percentage>"]
and angle_percentage = [%value.rec "<angle> | <percentage>"]
and angular_color_hint = [%value.rec "<angle-percentage>"]
and angular_color_stop = [%value.rec "<color> && [ <color-stop-angle> ]?"]
and angular_color_stop_list = [%value.rec
  "[ <angular-color-stop> [ ',' <angular-color-hint> ]? ]# ',' <angular-color-stop>"
]
and animateable_feature = [%value.rec
  "'scroll-position' | 'contents' | <custom-ident>"
]
and attachment = [%value.rec "'scroll' | 'fixed' | 'local'"]
and attr_matcher = [%value.rec "[ '~' | '|' | '^' | '$' | '*' ]? '='"]
and attr_modifier = [%value.rec "'i' | 's'"]
and attribute_selector = [%value.rec
  "'[' <wq-name> ']' | '[' <wq-name> <attr-matcher> [ <string-token> | <ident-token> ] [ <attr-modifier> ]? ']'"
]
and auto_repeat = [%value.rec
  "repeat( [ 'auto-fill' | 'auto-fit' ] ',' [ [ <line-names> ]? <fixed-size> ]+ [ <line-names> ]? )"
]
and auto_track_list = [%value.rec
  "[ [ <line-names> ]? [ <fixed-size> | <fixed-repeat> ] ]* [ <line-names> ]? <auto-repeat> [ [ <line-names> ]? [ <fixed-size> | <fixed-repeat> ] ]* [ <line-names> ]?"
]
and baseline_position = [%value.rec "[ 'first' | 'last' ]? 'baseline'"]
and basic_shape = [%value.rec
  "<inset()> | <circle()> | <ellipse()> | <polygon()> | <path()>"
]
and bg_image = [%value.rec "'none' | <image>"]
and bg_layer = [%value.rec
  "<bg-image> || <bg-position> [ '/' <bg-size> ]? || <repeat-style> || <attachment> || <box> || <box>"
]
and bg_position = [%value.rec
  "'left' | 'center' | 'right' | 'top' | 'bottom' | <length-percentage> | [ 'left' | 'center' | 'right' | <length-percentage> ] [ 'top' | 'center' | 'bottom' | <length-percentage> ] | [ 'center' | [ 'left' | 'right' ] [ <length-percentage> ]? ] && [ 'center' | [ 'top' | 'bottom' ] [ <length-percentage> ]? ]"
]
and bg_size = [%value.rec
  "[ <length-percentage> | 'auto' ]{1,2} | 'cover' | 'contain'"
]
and blend_mode = [%value.rec
  "'normal' | 'multiply' | 'screen' | 'overlay' | 'darken' | 'lighten' | 'color-dodge' | 'color-burn' | 'hard-light' | 'soft-light' | 'difference' | 'exclusion' | 'hue' | 'saturation' | 'color' | 'luminosity'"
]
and box = [%value.rec "'border-box' | 'padding-box' | 'content-box'"]
and calc_product = [%value.rec
  "<calc-value> [ '*' <calc-value> | '/' <number> ]*"
]
and calc_sum = [%value.rec "<calc-product> [ [ '+' | '-' ] <calc-product> ]*"]
and calc_value = [%value.rec
  "<number> | <dimension> | <percentage> | '(' <calc-sum> ')'"
]
and cf_final_image = [%value.rec "<image> | <color>"]
and cf_mixing_image = [%value.rec "[ <percentage> ]? && <image>"]
and class_selector = [%value.rec "'.' <ident-token>"]
and clip_source = [%value.rec "<url>"]
and color = [%value.rec
  "<rgb()> | <rgba()> | <hsl()> | <hsla()> | <hex-color> | <named-color> | 'currentcolor' | <deprecated-system-color>"
]
and color_stop = [%value.rec "<color-stop-length> | <color-stop-angle>"]
and color_stop_angle = [%value.rec "[ <angle-percentage> ]{1,2}"]
and color_stop_length = [%value.rec "[ <length-percentage> ]{1,2}"]
and color_stop_list = [%value.rec
  "[ <linear-color-stop> [ ',' <linear-color-hint> ]? ]# ',' <linear-color-stop>"
]
and combinator = [%value.rec "'>' | '+' | '~' | '||'"]
and common_lig_values = [%value.rec
  "'common-ligatures' | 'no-common-ligatures'"
]
and compat_auto = [%value.rec
  "'searchfield' | 'textarea' | 'push-button' | 'slider-horizontal' | 'checkbox' | 'radio' | 'square-button' | 'menulist' | 'listbox' | 'meter' | 'progress-bar'"
]
and complex_selector = [%value.rec
  "<compound-selector> [ [ <combinator> ]? <compound-selector> ]*"
]
and complex_selector_list = [%value.rec "[ <complex-selector> ]#"]
and composite_style = [%value.rec
  "'clear' | 'copy' | 'source-over' | 'source-in' | 'source-out' | 'source-atop' | 'destination-over' | 'destination-in' | 'destination-out' | 'destination-atop' | 'xor'"
]
and compositing_operator = [%value.rec
  "'add' | 'subtract' | 'intersect' | 'exclude'"
]
and compound_selector = [%value.rec
  "[ <type-selector> ]? [ <subclass-selector> ]* [ <pseudo-element-selector> [ <pseudo-class-selector> ]* ]*"
]
and compound_selector_list = [%value.rec "[ <compound-selector> ]#"]
and content_distribution = [%value.rec
  "'space-between' | 'space-around' | 'space-evenly' | 'stretch'"
]
and content_list = [%value.rec
  "[ <string> | 'contents' | <image> | <quote> | <target> | <leader()> ]+"
]
and content_position = [%value.rec
  "'center' | 'start' | 'end' | 'flex-start' | 'flex-end'"
]
and content_replacement = [%value.rec "<image>"]
and contextual_alt_values = [%value.rec "'contextual' | 'no-contextual'"]
and counter_style = [%value.rec "<counter-style-name>"]
and counter_style_name = [%value.rec "<custom-ident>"]
and cubic_bezier_timing_function = [%value.rec
  "'ease' | 'ease-in' | 'ease-out' | 'ease-in-out' | cubic-bezier( <number> ',' <number> ',' <number> ',' <number> )"
]
and deprecated_system_color = [%value.rec
  "'ActiveBorder' | 'ActiveCaption' | 'AppWorkspace' | 'Background' | 'ButtonFace' | 'ButtonHighlight' | 'ButtonShadow' | 'ButtonText' | 'CaptionText' | 'GrayText' | 'Highlight' | 'HighlightText' | 'InactiveBorder' | 'InactiveCaption' | 'InactiveCaptionText' | 'InfoBackground' | 'InfoText' | 'Menu' | 'MenuText' | 'Scrollbar' | 'ThreeDDarkShadow' | 'ThreeDFace' | 'ThreeDHighlight' | 'ThreeDLightShadow' | 'ThreeDShadow' | 'Window' | 'WindowFrame' | 'WindowText'"
]
and discretionary_lig_values = [%value.rec
  "'discretionary-ligatures' | 'no-discretionary-ligatures'"
]
and display_box = [%value.rec "'contents' | 'none'"]
and display_inside = [%value.rec
  "'flow' | 'flow-root' | 'table' | 'flex' | 'grid' | 'ruby'"
]
and display_internal = [%value.rec
  "'table-row-group' | 'table-header-group' | 'table-footer-group' | 'table-row' | 'table-cell' | 'table-column-group' | 'table-column' | 'table-caption' | 'ruby-base' | 'ruby-text' | 'ruby-base-container' | 'ruby-text-container'"
]
and display_legacy = [%value.rec
  "'inline-block' | 'inline-list-item' | 'inline-table' | 'inline-flex' | 'inline-grid'"
]
and display_listitem = [%value.rec
  "[ <display-outside> ]? && [ 'flow' | 'flow-root' ]? && 'list-item'"
]
and display_outside = [%value.rec "'block' | 'inline' | 'run-in'"]
and east_asian_variant_values = [%value.rec
  "'jis78' | 'jis83' | 'jis90' | 'jis04' | 'simplified' | 'traditional'"
]
and east_asian_width_values = [%value.rec
  "'full-width' | 'proportional-width'"
]
and ending_shape = [%value.rec "'circle' | 'ellipse'"]
and explicit_track_list = [%value.rec
  "[ [ <line-names> ]? <track-size> ]+ [ <line-names> ]?"
]
and family_name = [%value.rec "<string> | [ <custom-ident> ]+"]
and feature_tag_value = [%value.rec "<string> [ <integer> | 'on' | 'off' ]?"]
and feature_type = [%value.rec
  "'@stylistic' | '@historical-forms' | '@styleset' | '@character-variant' | '@swash' | '@ornaments' | '@annotation'"
]
and feature_value_block = [%value.rec
  "<feature-type> '{' <feature-value-declaration-list> '}'"
]
and feature_value_block_list = [%value.rec "[ <feature-value-block> ]+"]
and feature_value_declaration = [%value.rec
  "<custom-ident> ':' [ <integer> ]+ ';'"
]
and feature_value_declaration_list = [%value.rec "<feature-value-declaration>"]
and feature_value_name = [%value.rec "<custom-ident>"]
and fill_rule = [%value.rec "'nonzero' | 'evenodd'"]
and filter_function = [%value.rec
  "<blur()> | <brightness()> | <contrast()> | <drop-shadow()> | <grayscale()> | <hue-rotate()> | <invert()> | <opacity()> | <saturate()> | <sepia()>"
]
and filter_function_list = [%value.rec "[ <filter-function> | <url> ]+"]
and final_bg_layer = [%value.rec
  "<'background-color'> || <bg-image> || <bg-position> [ '/' <bg-size> ]? || <repeat-style> || <attachment> || <box> || <box>"
]
and fixed_breadth = [%value.rec "<length-percentage>"]
and fixed_repeat = [%value.rec
  "repeat( <positive-integer> ',' [ [ <line-names> ]? <fixed-size> ]+ [ <line-names> ]? )"
]
and fixed_size = [%value.rec
  "<fixed-breadth> | minmax( <fixed-breadth> ',' <track-breadth> ) | minmax( <inflexible-breadth> ',' <fixed-breadth> )"
]
and font_stretch_absolute = [%value.rec
  "'normal' | 'ultra-condensed' | 'extra-condensed' | 'condensed' | 'semi-condensed' | 'semi-expanded' | 'expanded' | 'extra-expanded' | 'ultra-expanded' | <percentage>"
]
and font_variant_css21 = [%value.rec "'normal' | 'small-caps'"]
and font_weight_absolute = [%value.rec "'normal' | 'bold' | <number>"]
and frequency_percentage = [%value.rec "<frequency> | <percentage>"]
and function_attr = [%value.rec
  "attr( <attr-name> [ <type-or-unit> ]? [ ',' <attr-fallback> ]? )"
]
and function_blur = [%value.rec "blur( <length> )"]
and function_brightness = [%value.rec "brightness( <number-percentage> )"]
and function_calc = [%value.rec "calc( <calc-sum> )"]
and function_circle = [%value.rec
  "circle( [ <shape-radius> ]? [ 'at' <position> ]? )"
]
and function_clamp = [%value.rec "clamp( [ <calc-sum> ]#{3} )"]
and function_conic_gradient = [%value.rec
  "conic-gradient( [ 'from' <angle> ]? [ 'at' <position> ]? ',' <angular-color-stop-list> )"
]
and function_contrast = [%value.rec "contrast( <number-percentage> )"]
and function_counter = [%value.rec
  "counter( <custom-ident> ',' [ <counter-style> ]? )"
]
and function_counters = [%value.rec
  "counters( <custom-ident> ',' <string> ',' [ <counter-style> ]? )"
]
and function_cross_fade = [%value.rec
  "cross-fade( <cf-mixing-image> ',' [ <cf-final-image> ]? )"
]
and function_drop_shadow = [%value.rec
  "drop-shadow( [ <length> ]{2,3} [ <color> ]? )"
]
and function_element = [%value.rec "element( <id-selector> )"]
and function_ellipse = [%value.rec
  "ellipse( [ [ <shape-radius> ]{2} ]? [ 'at' <position> ]? )"
]
and function_env = [%value.rec
  "env( <custom-ident> ',' [ <declaration-value> ]? )"
]
and function_fit_content = [%value.rec
  "fit-content( <length> | <percentage> )"
]
and function_grayscale = [%value.rec "grayscale( <number-percentage> )"]
and function_hsl = [%value.rec
  "hsl( <hue> <percentage> <percentage> [ '/' <alpha-value> ]? ) | hsl( <hue> ',' <percentage> ',' <percentage> ',' [ <alpha-value> ]? )"
]
and function_hsla = [%value.rec
  "hsla( <hue> <percentage> <percentage> [ '/' <alpha-value> ]? ) | hsla( <hue> ',' <percentage> ',' <percentage> ',' [ <alpha-value> ]? )"
]
and function_hue_rotate = [%value.rec "hue-rotate( <angle> )"]
and function_image = [%value.rec
  "image( <image-tags>? [ <image-src> ]? ',' [ <color> ]? )"
]
and function_image_set = [%value.rec "image-set( [ <image-set-option> ]# )"]
and function_inset = [%value.rec
  "inset( [ <length-percentage> ]{1,4} [ 'round' <'border-radius'> ]? )"
]
and function_invert = [%value.rec "invert( <number-percentage> )"]
and function_leader = [%value.rec "leader( <leader-type> )"]
and function_linear_gradient = [%value.rec
  "linear-gradient( [ <angle> | 'to' <side-or-corner> ]? ',' <color-stop-list> )"
]
and function_matrix = [%value.rec "matrix( [ <number> ]#{6} )"]
and function_matrix3d = [%value.rec "matrix3d( [ <number> ]#{16} )"]
and function_max = [%value.rec "max( [ <calc-sum> ]# )"]
and function_min = [%value.rec "min( [ <calc-sum> ]# )"]
and function_minmax = [%value.rec
  "minmax( [ <length> | <percentage> | 'min-content' | 'max-content' | 'auto' ] ',' [ <length> | <percentage> | <property_flex> | 'min-content' | 'max-content' | 'auto' ] )"
]
and function_opacity = [%value.rec "opacity( <number-percentage> )"]
and function_paint = [%value.rec
  "paint( <ident> ',' [ <declaration-value> ]? )"
]
and function_path = [%value.rec "path( [ <fill-rule> ',' ]? <string> )"]
and function_perspective = [%value.rec "perspective( <length> )"]
and function_polygon = [%value.rec
  "polygon( [ <fill-rule> ]? ',' [ <length-percentage> <length-percentage> ]# )"
]
and function_radial_gradient = [%value.rec
  "radial-gradient( [ <ending-shape> || <size> ]? [ 'at' <position> ]? ',' <color-stop-list> )"
]
and function_repeating_linear_gradient = [%value.rec
  "repeating-linear-gradient( [ <angle> | 'to' <side-or-corner> ]? ',' <color-stop-list> )"
]
and function_repeating_radial_gradient = [%value.rec
  "repeating-radial-gradient( [ <ending-shape> || <size> ]? [ 'at' <position> ]? ',' <color-stop-list> )"
]
and function_rgb = [%value.rec
  "rgb( [ <percentage> ]{3} [ '/' <alpha-value> ]? )
  | rgb( [ <number> ]{3} [ '/' <alpha-value> ]? )
  | rgb( [ <percentage> ]#{3} [ ',' <alpha-value> ]? )
  | rgb( [ <number> ]#{3} [ ',' <alpha-value> ]? )"
]
and function_rgba = [%value.rec
  "rgba( [ <percentage> ]{3} [ '/' <alpha-value> ]? ) | rgba( [ <number> ]{3} [ '/' <alpha-value> ]? ) | rgba( [ <percentage> ]#{3} [ ',' <alpha-value> ]? ) | rgba( [ <number> ]#{3} [ ',' <alpha-value> ]? )"
]
and function_rotate = [%value.rec "rotate( <angle> | <zero> )"]
and function_rotate3d = [%value.rec
  "rotate3d( <number> ',' <number> ',' <number> ',' [ <angle> | <zero> ] )"
]
and function_rotateX = [%value.rec "rotateX( <angle> | <zero> )"]
and function_rotateY = [%value.rec "rotateY( <angle> | <zero> )"]
and function_rotateZ = [%value.rec "rotateZ( <angle> | <zero> )"]
and function_saturate = [%value.rec "saturate( <number-percentage> )"]
and function_scale = [%value.rec "scale( <number> ',' [ <number> ]? )"]
and function_scale3d = [%value.rec
  "scale3d( <number> ',' <number> ',' <number> )"
]
and function_scaleX = [%value.rec "scaleX( <number> )"]
and function_scaleY = [%value.rec "scaleY( <number> )"]
and function_scaleZ = [%value.rec "scaleZ( <number> )"]
and function_sepia = [%value.rec "sepia( <number-percentage> )"]
and function_skew = [%value.rec
  "skew( [ <angle> | <zero> ] ',' [ <angle> | <zero> ]? )"
]
and function_skewX = [%value.rec "skewX( <angle> | <zero> )"]
and function_skewY = [%value.rec "skewY( <angle> | <zero> )"]
and function_target_counter = [%value.rec
  "target-counter( [ <string> | <url> ] ',' <custom-ident> ',' [ <counter-style> ]? )"
]
and function_target_counters = [%value.rec
  "target-counters( [ <string> | <url> ] ',' <custom-ident> ',' <string> ',' [ <counter-style> ]? )"
]
and function_target_text = [%value.rec
  "target-text( [ <string> | <url> ] ',' [ 'content' | 'before' | 'after' | 'first-letter' ]? )"
]
and function_translate = [%value.rec
  "translate( <length-percentage> ',' [ <length-percentage> ]? )"
]
and function_translate3d = [%value.rec
  "translate3d( <length-percentage> ',' <length-percentage> ',' <length> )"
]
and function_translateX = [%value.rec "translateX( <length-percentage> )"]
and function_translateY = [%value.rec "translateY( <length-percentage> )"]
and function_translateZ = [%value.rec "translateZ( <length> )"]
and function_var = [%value.rec
  "var( <custom-property-name> ',' [ <declaration-value> ]? )"
]
and general_enclosed = [%value.rec
  "<function-token> <any-value> ')' | '(' <ident> <any-value> ')'"
]
and generic_family = [%value.rec
  "'serif' | 'sans-serif' | 'cursive' | 'fantasy' | 'monospace'"
]
and generic_name = [%value.rec
  "'serif' | 'sans-serif' | 'cursive' | 'fantasy' | 'monospace'"
]
and geometry_box = [%value.rec
  "<shape-box> | 'fill-box' | 'stroke-box' | 'view-box'"
]
and gradient = [%value.rec
  "<linear-gradient()> | <repeating-linear-gradient()> | <radial-gradient()> | <repeating-radial-gradient()> | <conic-gradient()>"
]
and grid_line = [%value.rec
  "'auto' | <custom-ident> | <integer> && [ <custom-ident> ]? | 'span' && [ <integer> || <custom-ident> ]"
]
and historical_lig_values = [%value.rec
  "'historical-ligatures' | 'no-historical-ligatures'"
]
and hue = [%value.rec "<number> | <angle>"]
and id_selector = [%value.rec "<hash-token>"]
and image = [%value.rec
  "<url> | <image()> | <image-set()> | <element()> | <paint()> | <cross-fade()> | <gradient>"
]
and image_set_option = [%value.rec "[ <image> | <string> ] <resolution>"]
and image_src = [%value.rec "<url> | <string>"]
and image_tags = [%value.rec "'ltr' | 'rtl'"]
and inflexible_breadth = [%value.rec
  "<length> | <percentage> | 'min-content' | 'max-content' | 'auto'"
]
and keyframe_block = [%value.rec
  "[ <keyframe-selector> ]# '{' <declaration-list> '}'"
]
and keyframe_block_list = [%value.rec "[ <keyframe-block> ]+"]
and keyframe_selector = [%value.rec "'from' | 'to' | <percentage>"]
and keyframes_name = [%value.rec "<custom-ident> | <string>"]
and leader_type = [%value.rec "'dotted' | 'solid' | 'space' | <string>"]
and length_percentage = [%value.rec "<length> | <percentage>"]
and line_name_list = [%value.rec "[ <line-names> | <name-repeat> ]+"]
and line_names = [%value.rec "'[' [ <custom-ident> ]* ']'"]
and line_style = [%value.rec
  "'none' | 'hidden' | 'dotted' | 'dashed' | 'solid' | 'double' | 'groove' | 'ridge' | 'inset' | 'outset'"
]
and line_width = [%value.rec "<length> | 'thin' | 'medium' | 'thick'"]
and linear_color_hint = [%value.rec "<length-percentage>"]
and linear_color_stop = [%value.rec "<color> [ <color-stop-length> ]?"]
and mask_layer = [%value.rec
  "<mask-reference> || <position> [ '/' <bg-size> ]? || <repeat-style> || <geometry-box> || [ <geometry-box> | 'no-clip' ] || <compositing-operator> || <masking-mode>"
]
and mask_position = [%value.rec
  "[ <length-percentage> | 'left' | 'center' | 'right' ] [ <length-percentage> | 'top' | 'center' | 'bottom' ]?"
]
and mask_reference = [%value.rec "'none' | <image> | <mask-source>"]
and mask_source = [%value.rec "<url>"]
and masking_mode = [%value.rec "'alpha' | 'luminance' | 'match-source'"]
and media_and = [%value.rec "<media-in-parens> [ 'and' <media-in-parens> ]+"]
and media_condition = [%value.rec
  "<media-not> | <media-and> | <media-or> | <media-in-parens>"
]
and media_condition_without_or = [%value.rec
  "<media-not> | <media-and> | <media-in-parens>"
]
and media_feature = [%value.rec
  "'(' [ <mf-plain> | <mf-boolean> | <mf-range> ] ')'"
]
and media_in_parens = [%value.rec
  "'(' <media-condition> ')' | <media-feature> | <general-enclosed>"
]
and media_not = [%value.rec "'not' <media-in-parens>"]
and media_or = [%value.rec "<media-in-parens> [ 'or' <media-in-parens> ]+"]
and media_query = [%value.rec
  "<media-condition> | [ 'not' | 'only' ]? <media-type> [ 'and' <media-condition-without-or> ]?"
]
and media_query_list = [%value.rec "[ <media-query> ]#"]
and media_type = [%value.rec "<ident>"]
and mf_boolean = [%value.rec "<mf-name>"]
and mf_name = [%value.rec "<ident>"]
and mf_plain = [%value.rec "<mf-name> ':' <mf-value>"]
and mf_range = [%value.rec
  "<mf-name> [ '<' | '>' ]? [ '=' ]? <mf-value> | <mf-value> [ '<' | '>' ]? [ '=' ]? <mf-name> | <mf-value> '<' [ '=' ]? <mf-name> '<' [ '=' ]? <mf-value> | <mf-value> '>' [ '=' ]? <mf-name> '>' [ '=' ]? <mf-value>"
]
and mf_value = [%value.rec "<number> | <dimension> | <ident> | <ratio>"]
and named_color = [%value.rec
  "'transparent' | 'aliceblue' | 'antiquewhite' | 'aqua' | 'aquamarine' | 'azure' | 'beige' | 'bisque' | 'black' | 'blanchedalmond' | 'blue' | 'blueviolet' | 'brown' | 'burlywood' | 'cadetblue' | 'chartreuse' | 'chocolate' | 'coral' | 'cornflowerblue' | 'cornsilk' | 'crimson' | 'cyan' | 'darkblue' | 'darkcyan' | 'darkgoldenrod' | 'darkgray' | 'darkgreen' | 'darkgrey' | 'darkkhaki' | 'darkmagenta' | 'darkolivegreen' | 'darkorange' | 'darkorchid' | 'darkred' | 'darksalmon' | 'darkseagreen' | 'darkslateblue' | 'darkslategray' | 'darkslategrey' | 'darkturquoise' | 'darkviolet' | 'deeppink' | 'deepskyblue' | 'dimgray' | 'dimgrey' | 'dodgerblue' | 'firebrick' | 'floralwhite' | 'forestgreen' | 'fuchsia' | 'gainsboro' | 'ghostwhite' | 'gold' | 'goldenrod' | 'gray' | 'green' | 'greenyellow' | 'grey' | 'honeydew' | 'hotpink' | 'indianred' | 'indigo' | 'ivory' | 'khaki' | 'lavender' | 'lavenderblush' | 'lawngreen' | 'lemonchiffon' | 'lightblue' | 'lightcoral' | 'lightcyan' | 'lightgoldenrodyellow' | 'lightgray' | 'lightgreen' | 'lightgrey' | 'lightpink' | 'lightsalmon' | 'lightseagreen' | 'lightskyblue' | 'lightslategray' | 'lightslategrey' | 'lightsteelblue' | 'lightyellow' | 'lime' | 'limegreen' | 'linen' | 'magenta' | 'maroon' | 'mediumaquamarine' | 'mediumblue' | 'mediumorchid' | 'mediumpurple' | 'mediumseagreen' | 'mediumslateblue' | 'mediumspringgreen' | 'mediumturquoise' | 'mediumvioletred' | 'midnightblue' | 'mintcream' | 'mistyrose' | 'moccasin' | 'navajowhite' | 'navy' | 'oldlace' | 'olive' | 'olivedrab' | 'orange' | 'orangered' | 'orchid' | 'palegoldenrod' | 'palegreen' | 'paleturquoise' | 'palevioletred' | 'papayawhip' | 'peachpuff' | 'peru' | 'pink' | 'plum' | 'powderblue' | 'purple' | 'rebeccapurple' | 'red' | 'rosybrown' | 'royalblue' | 'saddlebrown' | 'salmon' | 'sandybrown' | 'seagreen' | 'seashell' | 'sienna' | 'silver' | 'skyblue' | 'slateblue' | 'slategray' | 'slategrey' | 'snow' | 'springgreen' | 'steelblue' | 'tan' | 'teal' | 'thistle' | 'tomato' | 'turquoise' | 'violet' | 'wheat' | 'white' | 'whitesmoke' | 'yellow' | 'yellowgreen'"
]
and namespace_prefix = [%value.rec "<ident>"]
and ns_prefix = [%value.rec "[ <ident-token> | '*' ]? '|'"]
and nth = [%value.rec "<an-plus-b> | 'even' | 'odd'"]
and number_percentage = [%value.rec "<number> | <percentage>"]
and numeric_figure_values = [%value.rec "'lining-nums' | 'oldstyle-nums'"]
and numeric_fraction_values = [%value.rec
  "'diagonal-fractions' | 'stacked-fractions'"
]
and numeric_spacing_values = [%value.rec
  "'proportional-nums' | 'tabular-nums'"
]
and outline_radius = [%value.rec "<length> | <percentage>"]
and overflow_position = [%value.rec "'unsafe' | 'safe'"]
and page_body = [%value.rec
  "[ <declaration> ]? [ ';' <page-body> ]? | <page-margin-box> <page-body>"
]
and page_margin_box = [%value.rec
  "<page-margin-box-type> '{' <declaration-list> '}'"
]
and page_margin_box_type = [%value.rec
  "'@top-left-corner' | '@top-left' | '@top-center' | '@top-right' | '@top-right-corner' | '@bottom-left-corner' | '@bottom-left' | '@bottom-center' | '@bottom-right' | '@bottom-right-corner' | '@left-top' | '@left-middle' | '@left-bottom' | '@right-top' | '@right-middle' | '@right-bottom'"
]
and page_selector = [%value.rec
  "[ <pseudo-page> ]+ | <ident> [ <pseudo-page> ]*"
]
and page_selector_list = [%value.rec "[ [ <page-selector> ]# ]?"]
and position = [%value.rec
  "[ 'left' | 'center' | 'right' ] || [ 'top' | 'center' | 'bottom' ] | [ 'left' | 'center' | 'right' | <length-percentage> ] [ 'top' | 'center' | 'bottom' | <length-percentage> ]? | [ 'left' | 'right' ] <length-percentage> && [ 'top' | 'bottom' ] <length-percentage>"
]
and property__moz_appearance = [%value.rec
  "'none' | 'button' | 'button-arrow-down' | 'button-arrow-next' | 'button-arrow-previous' | 'button-arrow-up' | 'button-bevel' | 'button-focus' | 'caret' | 'checkbox' | 'checkbox-container' | 'checkbox-label' | 'checkmenuitem' | 'dualbutton' | 'groupbox' | 'listbox' | 'listitem' | 'menuarrow' | 'menubar' | 'menucheckbox' | 'menuimage' | 'menuitem' | 'menuitemtext' | 'menulist' | 'menulist-button' | 'menulist-text' | 'menulist-textfield' | 'menupopup' | 'menuradio' | 'menuseparator' | 'meterbar' | 'meterchunk' | 'progressbar' | 'progressbar-vertical' | 'progresschunk' | 'progresschunk-vertical' | 'radio' | 'radio-container' | 'radio-label' | 'radiomenuitem' | 'range' | 'range-thumb' | 'resizer' | 'resizerpanel' | 'scale-horizontal' | 'scalethumbend' | 'scalethumb-horizontal' | 'scalethumbstart' | 'scalethumbtick' | 'scalethumb-vertical' | 'scale-vertical' | 'scrollbarbutton-down' | 'scrollbarbutton-left' | 'scrollbarbutton-right' | 'scrollbarbutton-up' | 'scrollbarthumb-horizontal' | 'scrollbarthumb-vertical' | 'scrollbartrack-horizontal' | 'scrollbartrack-vertical' | 'searchfield' | 'separator' | 'sheet' | 'spinner' | 'spinner-downbutton' | 'spinner-textfield' | 'spinner-upbutton' | 'splitter' | 'statusbar' | 'statusbarpanel' | 'tab' | 'tabpanel' | 'tabpanels' | 'tab-scroll-arrow-back' | 'tab-scroll-arrow-forward' | 'textfield' | 'textfield-multiline' | 'toolbar' | 'toolbarbutton' | 'toolbarbutton-dropdown' | 'toolbargripper' | 'toolbox' | 'tooltip' | 'treeheader' | 'treeheadercell' | 'treeheadersortarrow' | 'treeitem' | 'treeline' | 'treetwisty' | 'treetwistyopen' | 'treeview' | '-moz-mac-unified-toolbar' | '-moz-win-borderless-glass' | '-moz-win-browsertabbar-toolbox' | '-moz-win-communicationstext' | '-moz-win-communications-toolbox' | '-moz-win-exclude-glass' | '-moz-win-glass' | '-moz-win-mediatext' | '-moz-win-media-toolbox' | '-moz-window-button-box' | '-moz-window-button-box-maximized' | '-moz-window-button-close' | '-moz-window-button-maximize' | '-moz-window-button-minimize' | '-moz-window-button-restore' | '-moz-window-frame-bottom' | '-moz-window-frame-left' | '-moz-window-frame-right' | '-moz-window-titlebar' | '-moz-window-titlebar-maximized'"
]
and property__moz_binding = [%value.rec "<url> | 'none'"]
and property__moz_border_bottom_colors = [%value.rec "[ <color> ]+ | 'none'"]
and property__moz_border_left_colors = [%value.rec "[ <color> ]+ | 'none'"]
and property__moz_border_right_colors = [%value.rec "[ <color> ]+ | 'none'"]
and property__moz_border_top_colors = [%value.rec "[ <color> ]+ | 'none'"]
and property__moz_context_properties = [%value.rec
  "'none' | [ 'fill' | 'fill-opacity' | 'stroke' | 'stroke-opacity' ]#"
]
and property__moz_float_edge = [%value.rec
  "'border-box' | 'content-box' | 'margin-box' | 'padding-box'"
]
and property__moz_force_broken_image_icon = [%value.rec "<integer>"]
and property__moz_image_region = [%value.rec "<shape> | 'auto'"]
and property__moz_orient = [%value.rec
  "'inline' | 'block' | 'horizontal' | 'vertical'"
]
and property__moz_outline_radius = [%value.rec
  "[ <outline-radius> ]{1,4} [ '/' [ <outline-radius> ]{1,4} ]?"
]
and property__moz_outline_radius_bottomleft = [%value.rec "<outline-radius>"]
and property__moz_outline_radius_bottomright = [%value.rec "<outline-radius>"]
and property__moz_outline_radius_topleft = [%value.rec "<outline-radius>"]
and property__moz_outline_radius_topright = [%value.rec "<outline-radius>"]
and property__moz_stack_sizing = [%value.rec "'ignore' | 'stretch-to-fit'"]
and property__moz_text_blink = [%value.rec "'none' | 'blink'"]
and property__moz_user_focus = [%value.rec
  "'ignore' | 'normal' | 'select-after' | 'select-before' | 'select-menu' | 'select-same' | 'select-all' | 'none'"
]
and property__moz_user_input = [%value.rec
  "'auto' | 'none' | 'enabled' | 'disabled'"
]
and property__moz_user_modify = [%value.rec
  "'read-only' | 'read-write' | 'write-only'"
]
and property__moz_window_dragging = [%value.rec "'drag' | 'no-drag'"]
and property__moz_window_shadow = [%value.rec
  "'default' | 'menu' | 'tooltip' | 'sheet' | 'none'"
]
and property__ms_accelerator = [%value.rec "'false' | 'true'"]
and property__ms_block_progression = [%value.rec "'tb' | 'rl' | 'bt' | 'lr'"]
and property__ms_content_zoom_chaining = [%value.rec "'none' | 'chained'"]
and property__ms_content_zoom_limit = [%value.rec
  "<'-ms-content-zoom-limit-min'> <'-ms-content-zoom-limit-max'>"
]
and property__ms_content_zoom_limit_max = [%value.rec "<percentage>"]
and property__ms_content_zoom_limit_min = [%value.rec "<percentage>"]
and property__ms_content_zoom_snap = [%value.rec
  "<'-ms-content-zoom-snap-type'> || <'-ms-content-zoom-snap-points'>"
]
and property__ms_content_zoom_snap_points = [%value.rec
  "snapInterval( <percentage> ',' <percentage> ) | snapList( [ <percentage> ]# )"
]
and property__ms_content_zoom_snap_type = [%value.rec
  "'none' | 'proximity' | 'mandatory'"
]
and property__ms_content_zooming = [%value.rec "'none' | 'zoom'"]
and property__ms_filter = [%value.rec "<string>"]
and property__ms_flow_from = [%value.rec "[ 'none' | <custom-ident> ]#"]
and property__ms_flow_into = [%value.rec "[ 'none' | <custom-ident> ]#"]
and property__ms_high_contrast_adjust = [%value.rec "'auto' | 'none'"]
and property__ms_hyphenate_limit_chars = [%value.rec
  "'auto' | [ <integer> ]{1,3}"
]
and property__ms_hyphenate_limit_lines = [%value.rec "'no-limit' | <integer>"]
and property__ms_hyphenate_limit_zone = [%value.rec "<percentage> | <length>"]
and property__ms_ime_align = [%value.rec "'auto' | 'after'"]
and property__ms_overflow_style = [%value.rec
  "'auto' | 'none' | 'scrollbar' | '-ms-autohiding-scrollbar'"
]
and property__ms_scroll_chaining = [%value.rec "'chained' | 'none'"]
and property__ms_scroll_limit = [%value.rec
  "<'-ms-scroll-limit-x-min'> <'-ms-scroll-limit-y-min'> <'-ms-scroll-limit-x-max'> <'-ms-scroll-limit-y-max'>"
]
and property__ms_scroll_limit_x_max = [%value.rec "'auto' | <length>"]
and property__ms_scroll_limit_x_min = [%value.rec "<length>"]
and property__ms_scroll_limit_y_max = [%value.rec "'auto' | <length>"]
and property__ms_scroll_limit_y_min = [%value.rec "<length>"]
and property__ms_scroll_rails = [%value.rec "'none' | 'railed'"]
and property__ms_scroll_snap_points_x = [%value.rec
  "snapInterval( <length-percentage> ',' <length-percentage> ) | snapList( [ <length-percentage> ]# )"
]
and property__ms_scroll_snap_points_y = [%value.rec
  "snapInterval( <length-percentage> ',' <length-percentage> ) | snapList( [ <length-percentage> ]# )"
]
and property__ms_scroll_snap_type = [%value.rec
  "'none' | 'proximity' | 'mandatory'"
]
and property__ms_scroll_snap_x = [%value.rec
  "<'-ms-scroll-snap-type'> <'-ms-scroll-snap-points-x'>"
]
and property__ms_scroll_snap_y = [%value.rec
  "<'-ms-scroll-snap-type'> <'-ms-scroll-snap-points-y'>"
]
and property__ms_scroll_translation = [%value.rec
  "'none' | 'vertical-to-horizontal'"
]
and property__ms_scrollbar_3dlight_color = [%value.rec "<color>"]
and property__ms_scrollbar_arrow_color = [%value.rec "<color>"]
and property__ms_scrollbar_base_color = [%value.rec "<color>"]
and property__ms_scrollbar_darkshadow_color = [%value.rec "<color>"]
and property__ms_scrollbar_face_color = [%value.rec "<color>"]
and property__ms_scrollbar_highlight_color = [%value.rec "<color>"]
and property__ms_scrollbar_shadow_color = [%value.rec "<color>"]
and property__ms_scrollbar_track_color = [%value.rec "<color>"]
and property__ms_text_autospace = [%value.rec
  "'none' | 'ideograph-alpha' | 'ideograph-numeric' | 'ideograph-parenthesis' | 'ideograph-space'"
]
and property__ms_touch_select = [%value.rec "'grippers' | 'none'"]
and property__ms_user_select = [%value.rec "'none' | 'element' | 'text'"]
and property__ms_wrap_flow = [%value.rec
  "'auto' | 'both' | 'start' | 'end' | 'maximum' | 'clear'"
]
and property__ms_wrap_margin = [%value.rec "<length>"]
and property__ms_wrap_through = [%value.rec "'wrap' | 'none'"]
and property__webkit_appearance = [%value.rec
  "'none' | 'button' | 'button-bevel' | 'caret' | 'checkbox' | 'default-button' | 'inner-spin-button' | 'listbox' | 'listitem' | 'media-controls-background' | 'media-controls-fullscreen-background' | 'media-current-time-display' | 'media-enter-fullscreen-button' | 'media-exit-fullscreen-button' | 'media-fullscreen-button' | 'media-mute-button' | 'media-overlay-play-button' | 'media-play-button' | 'media-seek-back-button' | 'media-seek-forward-button' | 'media-slider' | 'media-sliderthumb' | 'media-time-remaining-display' | 'media-toggle-closed-captions-button' | 'media-volume-slider' | 'media-volume-slider-container' | 'media-volume-sliderthumb' | 'menulist' | 'menulist-button' | 'menulist-text' | 'menulist-textfield' | 'meter' | 'progress-bar' | 'progress-bar-value' | 'push-button' | 'radio' | 'searchfield' | 'searchfield-cancel-button' | 'searchfield-decoration' | 'searchfield-results-button' | 'searchfield-results-decoration' | 'slider-horizontal' | 'slider-vertical' | 'sliderthumb-horizontal' | 'sliderthumb-vertical' | 'square-button' | 'textarea' | 'textfield'"
]
and property__webkit_border_before = [%value.rec
  "<'border-width'> || <'border-style'> || <'color'>"
]
and property__webkit_border_before_color = [%value.rec "<'color'>"]
and property__webkit_border_before_style = [%value.rec "<'border-style'>"]
and property__webkit_border_before_width = [%value.rec "<'border-width'>"]
and property__webkit_box_reflect = [%value.rec
  "[ 'above' | 'below' | 'right' | 'left' ]? [ <length> ]? [ <image> ]?"
]
and property__webkit_line_clamp = [%value.rec "'none' | <integer>"]
and property__webkit_mask = [%value.rec
  "[ <mask-reference> || <position> [ '/' <bg-size> ]? || <repeat-style> || [ <box> | 'border' | 'padding' | 'content' | 'text' ] || [ <box> | 'border' | 'padding' | 'content' ] ]#"
]
and property__webkit_mask_attachment = [%value.rec "[ <attachment> ]#"]
and property__webkit_mask_clip = [%value.rec
  "[ <box> | 'border' | 'padding' | 'content' | 'text' ]#"
]
and property__webkit_mask_composite = [%value.rec "[ <composite-style> ]#"]
and property__webkit_mask_image = [%value.rec "[ <mask-reference> ]#"]
and property__webkit_mask_origin = [%value.rec
  "[ <box> | 'border' | 'padding' | 'content' ]#"
]
and property__webkit_mask_position = [%value.rec "[ <position> ]#"]
and property__webkit_mask_position_x = [%value.rec
  "[ <length-percentage> | 'left' | 'center' | 'right' ]#"
]
and property__webkit_mask_position_y = [%value.rec
  "[ <length-percentage> | 'top' | 'center' | 'bottom' ]#"
]
and property__webkit_mask_repeat = [%value.rec "[ <repeat-style> ]#"]
and property__webkit_mask_repeat_x = [%value.rec
  "'repeat' | 'no-repeat' | 'space' | 'round'"
]
and property__webkit_mask_repeat_y = [%value.rec
  "'repeat' | 'no-repeat' | 'space' | 'round'"
]
and property__webkit_mask_size = [%value.rec "[ <bg-size> ]#"]
and property__webkit_overflow_scrolling = [%value.rec "'auto' | 'touch'"]
and property__webkit_tap_highlight_color = [%value.rec "<color>"]
and property__webkit_text_fill_color = [%value.rec "<color>"]
and property__webkit_text_stroke = [%value.rec "<length> || <color>"]
and property__webkit_text_stroke_color = [%value.rec "<color>"]
and property__webkit_text_stroke_width = [%value.rec "<length>"]
and property__webkit_touch_callout = [%value.rec "'default' | 'none'"]
and property__webkit_user_modify = [%value.rec
  "'read-only' | 'read-write' | 'read-write-plaintext-only'"
]
and property_align_content = [%value.rec
  "'normal' | <baseline-position> | <content-distribution> | [ <overflow-position> ]? <content-position>"
]
and property_align_items = [%value.rec
  "'normal' | 'stretch' | <baseline-position> | [ <overflow-position> ]? <self-position>"
]
and property_align_self = [%value.rec
  "'auto' | 'normal' | 'stretch' | <baseline-position> | [ <overflow-position> ]? <self-position>"
]
and property_all = [%value.rec "'initial' | 'inherit' | 'unset' | 'revert'"]
and property_animation = [%value.rec "[ <single-animation> ]#"]
and property_animation_delay = [%value.rec "[ <time> ]#"]
and property_animation_direction = [%value.rec
  "[ <single-animation-direction> ]#"
]
and property_animation_duration = [%value.rec "[ <time> ]#"]
and property_animation_fill_mode = [%value.rec
  "[ <single-animation-fill-mode> ]#"
]
and property_animation_iteration_count = [%value.rec
  "[ <single-animation-iteration-count> ]#"
]
and property_animation_name = [%value.rec "[ 'none' | <keyframes-name> ]#"]
and property_animation_play_state = [%value.rec
  "[ <single-animation-play-state> ]#"
]
and property_animation_timing_function = [%value.rec "[ <timing-function> ]#"]
and property_appearance = [%value.rec
  "'none' | 'auto' | 'button' | 'textfield' | 'menulist-button' | <compat-auto>"
]
and property_aspect_ratio = [%value.rec "'auto' | <ratio>"]
and property_azimuth = [%value.rec
  "<angle> | [ 'left-side' | 'far-left' | 'left' | 'center-left' | 'center' | 'center-right' | 'right' | 'far-right' | 'right-side' ] || 'behind' | 'leftwards' | 'rightwards'"
]
and property_backdrop_filter = [%value.rec "'none' | <filter-function-list>"]
and property_backface_visibility = [%value.rec "'visible' | 'hidden'"]
and property_background = [%value.rec "[ <bg-layer> ',' ]* <final-bg-layer>"]
and property_background_attachment = [%value.rec "[ <attachment> ]#"]
and property_background_blend_mode = [%value.rec "[ <blend-mode> ]#"]
and property_background_clip = [%value.rec "[ <box> ]#"]
and property_background_color = [%value.rec "<color>"]
and property_background_image = [%value.rec "[ <bg-image> ]#"]
and property_background_origin = [%value.rec "[ <box> ]#"]
and property_background_position = [%value.rec "[ <bg-position> ]#"]
and property_background_position_x = [%value.rec
  "[ 'center' | [ 'left' | 'right' | 'x-start' | 'x-end' ]? [ <length-percentage> ]? ]#"
]
and property_background_position_y = [%value.rec
  "[ 'center' | [ 'top' | 'bottom' | 'y-start' | 'y-end' ]? [ <length-percentage> ]? ]#"
]
and property_background_repeat = [%value.rec "[ <repeat-style> ]#"]
and property_background_size = [%value.rec "[ <bg-size> ]#"]
and property_block_overflow = [%value.rec "'clip' | 'ellipsis' | <string>"]
and property_block_size = [%value.rec "<'width'>"]
and property_border = [%value.rec "<line-width> || <line-style> || <color>"]
and property_border_block = [%value.rec
  "<'border-top-width'> || <'border-top-style'> || <'color'>"
]
and property_border_block_color = [%value.rec "[ <'border-top-color'> ]{1,2}"]
and property_border_block_end = [%value.rec
  "<'border-top-width'> || <'border-top-style'> || <'color'>"
]
and property_border_block_end_color = [%value.rec "<'border-top-color'>"]
and property_border_block_end_style = [%value.rec "<'border-top-style'>"]
and property_border_block_end_width = [%value.rec "<'border-top-width'>"]
and property_border_block_start = [%value.rec
  "<'border-top-width'> || <'border-top-style'> || <'color'>"
]
and property_border_block_start_color = [%value.rec "<'border-top-color'>"]
and property_border_block_start_style = [%value.rec "<'border-top-style'>"]
and property_border_block_start_width = [%value.rec "<'border-top-width'>"]
and property_border_block_style = [%value.rec "<'border-top-style'>"]
and property_border_block_width = [%value.rec "<'border-top-width'>"]
and property_border_bottom = [%value.rec
  "<line-width> || <line-style> || <color>"
]
and property_border_bottom_color = [%value.rec "<'border-top-color'>"]
and property_border_bottom_left_radius = [%value.rec
  "[ <length-percentage> ]{1,2}"
]
and property_border_bottom_right_radius = [%value.rec
  "[ <length-percentage> ]{1,2}"
]
and property_border_bottom_style = [%value.rec "<line-style>"]
and property_border_bottom_width = [%value.rec "<line-width>"]
and property_border_collapse = [%value.rec "'collapse' | 'separate'"]
and property_border_color = [%value.rec "[ <color> ]{1,4}"]
and property_border_end_end_radius = [%value.rec
  "[ <length-percentage> ]{1,2}"
]
and property_border_end_start_radius = [%value.rec
  "[ <length-percentage> ]{1,2}"
]
and property_border_image = [%value.rec
  "<'border-image-source'> || <'border-image-slice'> [ '/' <'border-image-width'> | '/' [ <'border-image-width'> ]? '/' <'border-image-outset'> ]? || <'border-image-repeat'>"
]
and property_border_image_outset = [%value.rec "[ <length> | <number> ]{1,4}"]
and property_border_image_repeat = [%value.rec
  "[ 'stretch' | 'repeat' | 'round' | 'space' ]{1,2}"
]
and property_border_image_slice = [%value.rec
  "[ <number-percentage> ]{1,4} && [ 'fill' ]?"
]
and property_border_image_source = [%value.rec "'none' | <image>"]
and property_border_image_width = [%value.rec
  "[ <length-percentage> | <number> | 'auto' ]{1,4}"
]
and property_border_inline = [%value.rec
  "<'border-top-width'> || <'border-top-style'> || <'color'>"
]
and property_border_inline_color = [%value.rec "[ <'border-top-color'> ]{1,2}"]
and property_border_inline_end = [%value.rec
  "<'border-top-width'> || <'border-top-style'> || <'color'>"
]
and property_border_inline_end_color = [%value.rec "<'border-top-color'>"]
and property_border_inline_end_style = [%value.rec "<'border-top-style'>"]
and property_border_inline_end_width = [%value.rec "<'border-top-width'>"]
and property_border_inline_start = [%value.rec
  "<'border-top-width'> || <'border-top-style'> || <'color'>"
]
and property_border_inline_start_color = [%value.rec "<'border-top-color'>"]
and property_border_inline_start_style = [%value.rec "<'border-top-style'>"]
and property_border_inline_start_width = [%value.rec "<'border-top-width'>"]
and property_border_inline_style = [%value.rec "<'border-top-style'>"]
and property_border_inline_width = [%value.rec "<'border-top-width'>"]
and property_border_left = [%value.rec
  "<line-width> || <line-style> || <color>"
]
and property_border_left_color = [%value.rec "<color>"]
and property_border_left_style = [%value.rec "<line-style>"]
and property_border_left_width = [%value.rec "<line-width>"]
and property_border_radius = [%value.rec
  "[ <length-percentage> ]{1,4} [ '/' [ <length-percentage> ]{1,4} ]?"
]
and property_border_right = [%value.rec
  "<line-width> || <line-style> || <color>"
]
and property_border_right_color = [%value.rec "<color>"]
and property_border_right_style = [%value.rec "<line-style>"]
and property_border_right_width = [%value.rec "<line-width>"]
and property_border_spacing = [%value.rec "<length> [ <length> ]?"]
and property_border_start_end_radius = [%value.rec
  "[ <length-percentage> ]{1,2}"
]
and property_border_start_start_radius = [%value.rec
  "[ <length-percentage> ]{1,2}"
]
and property_border_style = [%value.rec "[ <line-style> ]{1,4}"]
and property_border_top = [%value.rec
  "<line-width> || <line-style> || <color>"
]
and property_border_top_color = [%value.rec "<color>"]
and property_border_top_left_radius = [%value.rec
  "[ <length-percentage> ]{1,2}"
]
and property_border_top_right_radius = [%value.rec
  "[ <length-percentage> ]{1,2}"
]
and property_border_top_style = [%value.rec "<line-style>"]
and property_border_top_width = [%value.rec "<line-width>"]
and property_border_width = [%value.rec "[ <line-width> ]{1,4}"]
and property_bottom = [%value.rec "<length> | <percentage> | 'auto'"]
and property_box_align = [%value.rec
  "'start' | 'center' | 'end' | 'baseline' | 'stretch'"
]
and property_box_decoration_break = [%value.rec "'slice' | 'clone'"]
and property_box_direction = [%value.rec "'normal' | 'reverse' | 'inherit'"]
and property_box_flex = [%value.rec "<number>"]
and property_box_flex_group = [%value.rec "<integer>"]
and property_box_lines = [%value.rec "'single' | 'multiple'"]
and property_box_ordinal_group = [%value.rec "<integer>"]
and property_box_orient = [%value.rec
  "'horizontal' | 'vertical' | 'inline-axis' | 'block-axis' | 'inherit'"
]
and property_box_pack = [%value.rec "'start' | 'center' | 'end' | 'justify'"]
and property_box_shadow = [%value.rec "'none' | [ <shadow> ]#"]
and property_box_sizing = [%value.rec "'content-box' | 'border-box'"]
and property_break_after = [%value.rec
  "'auto' | 'avoid' | 'always' | 'all' | 'avoid-page' | 'page' | 'left' | 'right' | 'recto' | 'verso' | 'avoid-column' | 'column' | 'avoid-region' | 'region'"
]
and property_break_before = [%value.rec
  "'auto' | 'avoid' | 'always' | 'all' | 'avoid-page' | 'page' | 'left' | 'right' | 'recto' | 'verso' | 'avoid-column' | 'column' | 'avoid-region' | 'region'"
]
and property_break_inside = [%value.rec
  "'auto' | 'avoid' | 'avoid-page' | 'avoid-column' | 'avoid-region'"
]
and property_caption_side = [%value.rec
  "'top' | 'bottom' | 'block-start' | 'block-end' | 'inline-start' | 'inline-end'"
]
and property_caret_color = [%value.rec "'auto' | <color>"]
and property_clear = [%value.rec
  "'none' | 'left' | 'right' | 'both' | 'inline-start' | 'inline-end'"
]
and property_clip = [%value.rec "<shape> | 'auto'"]
and property_clip_path = [%value.rec
  "<clip-source> | <basic-shape> || <geometry-box> | 'none'"
]
and property_color = [%value.rec "<color>"]
and property_color_adjust = [%value.rec "'economy' | 'exact'"]
and property_column_count = [%value.rec "<integer> | 'auto'"]
and property_column_fill = [%value.rec "'auto' | 'balance' | 'balance-all'"]
and property_column_gap = [%value.rec "'normal' | <length-percentage>"]
and property_column_rule = [%value.rec
  "<'column-rule-width'> || <'column-rule-style'> || <'column-rule-color'>"
]
and property_column_rule_color = [%value.rec "<color>"]
and property_column_rule_style = [%value.rec "<'border-style'>"]
and property_column_rule_width = [%value.rec "<'border-width'>"]
and property_column_span = [%value.rec "'none' | 'all'"]
and property_column_width = [%value.rec "<length> | 'auto'"]
and property_columns = [%value.rec "<'column-width'> || <'column-count'>"]
and property_contain = [%value.rec
  "'none' | 'strict' | 'content' | 'size' || 'layout' || 'style' || 'paint'"
]
and property_content = [%value.rec
  "'normal' | 'none' | [ <content-replacement> | <content-list> ] [ '/' <string> ]?"
]
and property_counter_increment = [%value.rec
  "[ <custom-ident> [ <integer> ]? ]+ | 'none'"
]
and property_counter_reset = [%value.rec
  "[ <custom-ident> [ <integer> ]? ]+ | 'none'"
]
and property_counter_set = [%value.rec
  "[ <custom-ident> [ <integer> ]? ]+ | 'none'"
]
and property_cursor = [%value.rec
  "[ <url> [ <x> <y> ]? ',' ]* [ 'auto' | 'default' | 'none' | 'context-menu' | 'help' | 'pointer' | 'progress' | 'wait' | 'cell' | 'crosshair' | 'text' | 'vertical-text' | 'alias' | 'copy' | 'move' | 'no-drop' | 'not-allowed' | 'e-resize' | 'n-resize' | 'ne-resize' | 'nw-resize' | 's-resize' | 'se-resize' | 'sw-resize' | 'w-resize' | 'ew-resize' | 'ns-resize' | 'nesw-resize' | 'nwse-resize' | 'col-resize' | 'row-resize' | 'all-scroll' | 'zoom-in' | 'zoom-out' | 'grab' | 'grabbing' ]"
]
and property_direction = [%value.rec "'ltr' | 'rtl'"]
and property_display = [%value.rec
  "<display-outside> || <display-inside> | <display-listitem> | <display-internal> | <display-box> | <display-legacy>"
]
and property_empty_cells = [%value.rec "'show' | 'hide'"]
and property_filter = [%value.rec "'none' | <filter-function-list>"]
and property_flex = [%value.rec
  "'none' | <'flex-grow'> [ <'flex-shrink'> ]? || <'flex-basis'>"
]
and property_flex_basis = [%value.rec "'content' | <'width'>"]
and property_flex_direction = [%value.rec
  "'row' | 'row-reverse' | 'column' | 'column-reverse'"
]
and property_flex_flow = [%value.rec "<'flex-direction'> || <'flex-wrap'>"]
and property_flex_grow = [%value.rec "<number>"]
and property_flex_shrink = [%value.rec "<number>"]
and property_flex_wrap = [%value.rec "'nowrap' | 'wrap' | 'wrap-reverse'"]
and property_float = [%value.rec
  "'left' | 'right' | 'none' | 'inline-start' | 'inline-end'"
]
and property_font = [%value.rec
  "[ <'font-style'> || <font-variant-css21> || <'font-weight'> || <'font-stretch'> ]? <'font-size'> [ '/' <'line-height'> ]? <'font-family'> | 'caption' | 'icon' | 'menu' | 'message-box' | 'small-caption' | 'status-bar'"
]
and property_font_family = [%value.rec "[ <family-name> | <generic-family> ]#"]
and property_font_feature_settings = [%value.rec
  "'normal' | [ <feature-tag-value> ]#"
]
and property_font_kerning = [%value.rec "'auto' | 'normal' | 'none'"]
and property_font_language_override = [%value.rec "'normal' | <string>"]
and property_font_optical_sizing = [%value.rec "'auto' | 'none'"]
and property_font_size = [%value.rec
  "<absolute-size> | <relative-size> | <length-percentage>"
]
and property_font_size_adjust = [%value.rec "'none' | <number>"]
and property_font_smooth = [%value.rec
  "'auto' | 'never' | 'always' | <absolute-size> | <length>"
]
and property_font_stretch = [%value.rec "<font-stretch-absolute>"]
and property_font_style = [%value.rec
  "'normal' | 'italic' | 'oblique' [ <angle> ]?"
]
and property_font_synthesis = [%value.rec "'none' | 'weight' || 'style'"]
and property_font_variant = [%value.rec
  "'normal' | 'none' | <common-lig-values> || <discretionary-lig-values> || <historical-lig-values> || <contextual-alt-values> || stylistic( <feature-value-name> ) || 'historical-forms' || styleset( [ <feature-value-name> ]# ) || character-variant( [ <feature-value-name> ]# ) || swash( <feature-value-name> ) || ornaments( <feature-value-name> ) || annotation( <feature-value-name> ) || [ 'small-caps' | 'all-small-caps' | 'petite-caps' | 'all-petite-caps' | 'unicase' | 'titling-caps' ] || <numeric-figure-values> || <numeric-spacing-values> || <numeric-fraction-values> || 'ordinal' || 'slashed-zero' || <east-asian-variant-values> || <east-asian-width-values> || 'ruby'"
]
and property_font_variant_alternates = [%value.rec
  "'normal' | stylistic( <feature-value-name> ) || 'historical-forms' || styleset( [ <feature-value-name> ]# ) || character-variant( [ <feature-value-name> ]# ) || swash( <feature-value-name> ) || ornaments( <feature-value-name> ) || annotation( <feature-value-name> )"
]
and property_font_variant_caps = [%value.rec
  "'normal' | 'small-caps' | 'all-small-caps' | 'petite-caps' | 'all-petite-caps' | 'unicase' | 'titling-caps'"
]
and property_font_variant_east_asian = [%value.rec
  "'normal' | <east-asian-variant-values> || <east-asian-width-values> || 'ruby'"
]
and property_font_variant_ligatures = [%value.rec
  "'normal' | 'none' | <common-lig-values> || <discretionary-lig-values> || <historical-lig-values> || <contextual-alt-values>"
]
and property_font_variant_numeric = [%value.rec
  "'normal' | <numeric-figure-values> || <numeric-spacing-values> || <numeric-fraction-values> || 'ordinal' || 'slashed-zero'"
]
and property_font_variant_position = [%value.rec "'normal' | 'sub' | 'super'"]
and property_font_variation_settings = [%value.rec
  "'normal' | [ <string> <number> ]#"
]
and property_font_weight = [%value.rec
  "<font-weight-absolute> | 'bolder' | 'lighter'"
]
and property_gap = [%value.rec "<'row-gap'> [ <'column-gap'> ]?"]
and property_grid = [%value.rec
  "<'grid-template'> | <'grid-template-rows'> '/' [ 'auto-flow' && [ 'dense' ]? ] [ <'grid-auto-columns'> ]? | [ 'auto-flow' && [ 'dense' ]? ] [ <'grid-auto-rows'> ]? '/' <'grid-template-columns'>"
]
and property_grid_area = [%value.rec "<grid-line> [ '/' <grid-line> ]{0,3}"]
and property_grid_auto_columns = [%value.rec "[ <track-size> ]+"]
and property_grid_auto_flow = [%value.rec "[ 'row' | 'column' ] || 'dense'"]
and property_grid_auto_rows = [%value.rec "[ <track-size> ]+"]
and property_grid_column = [%value.rec "<grid-line> [ '/' <grid-line> ]?"]
and property_grid_column_end = [%value.rec "<grid-line>"]
and property_grid_column_gap = [%value.rec "<length-percentage>"]
and property_grid_column_start = [%value.rec "<grid-line>"]
and property_grid_gap = [%value.rec
  "<'grid-row-gap'> [ <'grid-column-gap'> ]?"
]
and property_grid_row = [%value.rec "<grid-line> [ '/' <grid-line> ]?"]
and property_grid_row_end = [%value.rec "<grid-line>"]
and property_grid_row_gap = [%value.rec "<length-percentage>"]
and property_grid_row_start = [%value.rec "<grid-line>"]
and property_grid_template = [%value.rec
  "'none' | <'grid-template-rows'> '/' <'grid-template-columns'> | [ [ <line-names> ]? <string> [ <track-size> ]? [ <line-names> ]? ]+ [ '/' <explicit-track-list> ]?"
]
and property_grid_template_areas = [%value.rec "'none' | [ <string> ]+"]
and property_grid_template_columns = [%value.rec
  "'none' | <track-list> | <auto-track-list> | 'subgrid' [ <line-name-list> ]?"
]
and property_grid_template_rows = [%value.rec
  "'none' | <track-list> | <auto-track-list> | 'subgrid' [ <line-name-list> ]?"
]
and property_hanging_punctuation = [%value.rec
  "'none' | 'first' || [ 'force-end' | 'allow-end' ] || 'last'"
]
and property_height = [%value.rec
  "'auto' | <length> | <percentage> | 'min-content' | 'max-content' | fit-content( <length-percentage> )"
]
and property_hyphens = [%value.rec "'none' | 'manual' | 'auto'"]
and property_image_orientation = [%value.rec
  "'from-image' | <angle> | [ <angle> ]? 'flip'"
]
and property_image_rendering = [%value.rec
  "'auto' | 'crisp-edges' | 'pixelated'"
]
and property_image_resolution = [%value.rec
  "[ 'from-image' || <resolution> ] && [ 'snap' ]?"
]
and property_ime_mode = [%value.rec
  "'auto' | 'normal' | 'active' | 'inactive' | 'disabled'"
]
and property_initial_letter = [%value.rec "'normal' | <number> [ <integer> ]?"]
and property_initial_letter_align = [%value.rec
  "'auto' | 'alphabetic' | 'hanging' | 'ideographic'"
]
and property_inline_size = [%value.rec "<'width'>"]
and property_inset = [%value.rec "[ <'top'> ]{1,4}"]
and property_inset_block = [%value.rec "[ <'top'> ]{1,2}"]
and property_inset_block_end = [%value.rec "<'top'>"]
and property_inset_block_start = [%value.rec "<'top'>"]
and property_inset_inline = [%value.rec "[ <'top'> ]{1,2}"]
and property_inset_inline_end = [%value.rec "<'top'>"]
and property_inset_inline_start = [%value.rec "<'top'>"]
and property_isolation = [%value.rec "'auto' | 'isolate'"]
and property_justify_content = [%value.rec
  "'normal' | <content-distribution> | [ <overflow-position> ]? [ <content-position> | 'left' | 'right' ]"
]
and property_justify_items = [%value.rec
  "'normal' | 'stretch' | <baseline-position> | [ <overflow-position> ]? [ <self-position> | 'left' | 'right' ] | 'legacy' | 'legacy' && [ 'left' | 'right' | 'center' ]"
]
and property_justify_self = [%value.rec
  "'auto' | 'normal' | 'stretch' | <baseline-position> | [ <overflow-position> ]? [ <self-position> | 'left' | 'right' ]"
]
and property_left = [%value.rec "<length> | <percentage> | 'auto'"]
and property_letter_spacing = [%value.rec "'normal' | <length>"]
and property_line_break = [%value.rec
  "'auto' | 'loose' | 'normal' | 'strict' | 'anywhere'"
]
and property_line_clamp = [%value.rec "'none' | <integer>"]
and property_line_height = [%value.rec
  "'normal' | <number> | <length> | <percentage>"
]
and property_line_height_step = [%value.rec "<length>"]
and property_list_style = [%value.rec
  "<'list-style-type'> || <'list-style-position'> || <'list-style-image'>"
]
and property_list_style_image = [%value.rec "<url> | 'none'"]
and property_list_style_position = [%value.rec "'inside' | 'outside'"]
and property_list_style_type = [%value.rec
  "<counter-style> | <string> | 'none'"
]
and property_margin = [%value.rec "[ <length> | <percentage> | 'auto' ]{1,4}"]
and property_margin_block = [%value.rec "[ <'margin-left'> ]{1,2}"]
and property_margin_block_end = [%value.rec "<'margin-left'>"]
and property_margin_block_start = [%value.rec "<'margin-left'>"]
and property_margin_bottom = [%value.rec "<length> | <percentage> | 'auto'"]
and property_margin_inline = [%value.rec "[ <'margin-left'> ]{1,2}"]
and property_margin_inline_end = [%value.rec "<'margin-left'>"]
and property_margin_inline_start = [%value.rec "<'margin-left'>"]
and property_margin_left = [%value.rec "<length> | <percentage> | 'auto'"]
and property_margin_right = [%value.rec "<length> | <percentage> | 'auto'"]
and property_margin_top = [%value.rec "<length> | <percentage> | 'auto'"]
and property_margin_trim = [%value.rec "'none' | 'in-flow' | 'all'"]
and property_mask = [%value.rec "[ <mask-layer> ]#"]
and property_mask_border = [%value.rec
  "<'mask-border-source'> || <'mask-border-slice'> [ '/' [ <'mask-border-width'> ]? [ '/' <'mask-border-outset'> ]? ]? || <'mask-border-repeat'> || <'mask-border-mode'>"
]
and property_mask_border_mode = [%value.rec "'luminance' | 'alpha'"]
and property_mask_border_outset = [%value.rec "[ <length> | <number> ]{1,4}"]
and property_mask_border_repeat = [%value.rec
  "[ 'stretch' | 'repeat' | 'round' | 'space' ]{1,2}"
]
and property_mask_border_slice = [%value.rec
  "[ <number-percentage> ]{1,4} [ 'fill' ]?"
]
and property_mask_border_source = [%value.rec "'none' | <image>"]
and property_mask_border_width = [%value.rec
  "[ <length-percentage> | <number> | 'auto' ]{1,4}"
]
and property_mask_clip = [%value.rec "[ <geometry-box> | 'no-clip' ]#"]
and property_mask_composite = [%value.rec "[ <compositing-operator> ]#"]
and property_mask_image = [%value.rec "[ <mask-reference> ]#"]
and property_mask_mode = [%value.rec "[ <masking-mode> ]#"]
and property_mask_origin = [%value.rec "[ <geometry-box> ]#"]
and property_mask_position = [%value.rec "[ <position> ]#"]
and property_mask_repeat = [%value.rec "[ <repeat-style> ]#"]
and property_mask_size = [%value.rec "[ <bg-size> ]#"]
and property_mask_type = [%value.rec "'luminance' | 'alpha'"]
and property_max_block_size = [%value.rec "<'max-width'>"]
and property_max_height = [%value.rec
  "'auto' | <length> | <percentage> | 'min-content' | 'max-content' | fit-content( <length-percentage> )"
]
and property_max_inline_size = [%value.rec "<'max-width'>"]
and property_max_lines = [%value.rec "'none' | <integer>"]
and property_max_width = [%value.rec
  "'auto' | <length> | <percentage> | 'min-content' | 'max-content' | fit-content( <length-percentage> )"
]
and property_min_block_size = [%value.rec "<'min-width'>"]
and property_min_height = [%value.rec
  "'auto' | <length> | <percentage> | 'min-content' | 'max-content' | fit-content( <length-percentage> )"
]
and property_min_inline_size = [%value.rec "<'min-width'>"]
and property_min_width = [%value.rec
  "'auto' | <length> | <percentage> | 'min-content' | 'max-content' | fit-content( <length-percentage> )"
]
and property_mix_blend_mode = [%value.rec "<blend-mode>"]
and property_object_fit = [%value.rec
  "'fill' | 'contain' | 'cover' | 'none' | 'scale-down'"
]
and property_object_position = [%value.rec "<position>"]
and property_offset = [%value.rec
  "[ <'offset-position'> ]? [ <'offset-path'> [ <'offset-distance'> || <'offset-rotate'> ]? ]? [ '/' <'offset-anchor'> ]?"
]
and property_offset_anchor = [%value.rec "'auto' | <position>"]
and property_offset_distance = [%value.rec "<length-percentage>"]
and property_offset_path = [%value.rec
  "'none' | ray( <angle> && [ <size> ]? && [ 'contain' ]? ) | <path()> | <url> | <basic-shape> || <geometry-box>"
]
and property_offset_position = [%value.rec "'auto' | <position>"]
and property_offset_rotate = [%value.rec "[ 'auto' | 'reverse' ] || <angle>"]
and property_opacity = [%value.rec "<alpha-value>"]
and property_order = [%value.rec "<integer>"]
and property_orphans = [%value.rec "<integer>"]
and property_outline = [%value.rec
  "<'outline-color'> || <'outline-style'> || <'outline-width'>"
]
and property_outline_color = [%value.rec "<color> | 'invert'"]
and property_outline_offset = [%value.rec "<length>"]
and property_outline_style = [%value.rec "'auto' | <'border-style'>"]
and property_outline_width = [%value.rec "<line-width>"]
and property_overflow = [%value.rec
  "[ 'visible' | 'hidden' | 'clip' | 'scroll' | 'auto' ]{1,2}"
]
and property_overflow_anchor = [%value.rec "'auto' | 'none'"]
and property_overflow_block = [%value.rec
  "'visible' | 'hidden' | 'clip' | 'scroll' | 'auto'"
]
and property_overflow_clip_box = [%value.rec "'padding-box' | 'content-box'"]
and property_overflow_inline = [%value.rec
  "'visible' | 'hidden' | 'clip' | 'scroll' | 'auto'"
]
and property_overflow_wrap = [%value.rec
  "'normal' | 'break-word' | 'anywhere'"
]
and property_overflow_x = [%value.rec
  "'visible' | 'hidden' | 'clip' | 'scroll' | 'auto'"
]
and property_overflow_y = [%value.rec
  "'visible' | 'hidden' | 'clip' | 'scroll' | 'auto'"
]
and property_overscroll_behavior = [%value.rec
  "[ 'contain' | 'none' | 'auto' ]{1,2}"
]
and property_overscroll_behavior_block = [%value.rec
  "'contain' | 'none' | 'auto'"
]
and property_overscroll_behavior_inline = [%value.rec
  "'contain' | 'none' | 'auto'"
]
and property_overscroll_behavior_x = [%value.rec "'contain' | 'none' | 'auto'"]
and property_overscroll_behavior_y = [%value.rec "'contain' | 'none' | 'auto'"]
and property_padding = [%value.rec "[ <length> | <percentage> ]{1,4}"]
and property_padding_block = [%value.rec "[ <'padding-left'> ]{1,2}"]
and property_padding_block_end = [%value.rec "<'padding-left'>"]
and property_padding_block_start = [%value.rec "<'padding-left'>"]
and property_padding_bottom = [%value.rec "<length> | <percentage>"]
and property_padding_inline = [%value.rec "[ <'padding-left'> ]{1,2}"]
and property_padding_inline_end = [%value.rec "<'padding-left'>"]
and property_padding_inline_start = [%value.rec "<'padding-left'>"]
and property_padding_left = [%value.rec "<length> | <percentage>"]
and property_padding_right = [%value.rec "<length> | <percentage>"]
and property_padding_top = [%value.rec "<length> | <percentage>"]
and property_page_break_after = [%value.rec
  "'auto' | 'always' | 'avoid' | 'left' | 'right' | 'recto' | 'verso'"
]
and property_page_break_before = [%value.rec
  "'auto' | 'always' | 'avoid' | 'left' | 'right' | 'recto' | 'verso'"
]
and property_page_break_inside = [%value.rec "'auto' | 'avoid'"]
and property_paint_order = [%value.rec
  "'normal' | 'fill' || 'stroke' || 'markers'"
]
and property_perspective = [%value.rec "'none' | <length>"]
and property_perspective_origin = [%value.rec "<position>"]
and property_place_content = [%value.rec
  "<'align-content'> [ <'justify-content'> ]?"
]
and property_place_items = [%value.rec
  "<'align-items'> [ <'justify-items'> ]?"
]
and property_place_self = [%value.rec "<'align-self'> [ <'justify-self'> ]?"]
and property_pointer_events = [%value.rec
  "'auto' | 'none' | 'visiblePainted' | 'visibleFill' | 'visibleStroke' | 'visible' | 'painted' | 'fill' | 'stroke' | 'all' | 'inherit'"
]
and property_position = [%value.rec
  "'static' | 'relative' | 'absolute' | 'sticky' | 'fixed'"
]
and property_quotes = [%value.rec "'none' | 'auto' | [ <string> <string> ]+"]
and property_resize = [%value.rec
  "'none' | 'both' | 'horizontal' | 'vertical' | 'block' | 'inline'"
]
and property_right = [%value.rec "<length> | <percentage> | 'auto'"]
and property_rotate = [%value.rec
  "'none' | <angle> | [ 'x' | 'y' | 'z' | [ <number> ]{3} ] && <angle>"
]
and property_row_gap = [%value.rec "'normal' | <length-percentage>"]
and property_ruby_align = [%value.rec
  "'start' | 'center' | 'space-between' | 'space-around'"
]
and property_ruby_merge = [%value.rec "'separate' | 'collapse' | 'auto'"]
and property_ruby_position = [%value.rec
  "'over' | 'under' | 'inter-character'"
]
and property_scale = [%value.rec "'none' | [ <number> ]{1,3}"]
and property_scroll_behavior = [%value.rec "'auto' | 'smooth'"]
and property_scroll_margin = [%value.rec "[ <length> ]{1,4}"]
and property_scroll_margin_block = [%value.rec "[ <length> ]{1,2}"]
and property_scroll_margin_block_end = [%value.rec "<length>"]
and property_scroll_margin_block_start = [%value.rec "<length>"]
and property_scroll_margin_bottom = [%value.rec "<length>"]
and property_scroll_margin_inline = [%value.rec "[ <length> ]{1,2}"]
and property_scroll_margin_inline_end = [%value.rec "<length>"]
and property_scroll_margin_inline_start = [%value.rec "<length>"]
and property_scroll_margin_left = [%value.rec "<length>"]
and property_scroll_margin_right = [%value.rec "<length>"]
and property_scroll_margin_top = [%value.rec "<length>"]
and property_scroll_padding = [%value.rec
  "[ 'auto' | <length-percentage> ]{1,4}"
]
and property_scroll_padding_block = [%value.rec
  "[ 'auto' | <length-percentage> ]{1,2}"
]
and property_scroll_padding_block_end = [%value.rec
  "'auto' | <length-percentage>"
]
and property_scroll_padding_block_start = [%value.rec
  "'auto' | <length-percentage>"
]
and property_scroll_padding_bottom = [%value.rec
  "'auto' | <length-percentage>"
]
and property_scroll_padding_inline = [%value.rec
  "[ 'auto' | <length-percentage> ]{1,2}"
]
and property_scroll_padding_inline_end = [%value.rec
  "'auto' | <length-percentage>"
]
and property_scroll_padding_inline_start = [%value.rec
  "'auto' | <length-percentage>"
]
and property_scroll_padding_left = [%value.rec "'auto' | <length-percentage>"]
and property_scroll_padding_right = [%value.rec "'auto' | <length-percentage>"]
and property_scroll_padding_top = [%value.rec "'auto' | <length-percentage>"]
and property_scroll_snap_align = [%value.rec
  "[ 'none' | 'start' | 'end' | 'center' ]{1,2}"
]
and property_scroll_snap_coordinate = [%value.rec "'none' | [ <position> ]#"]
and property_scroll_snap_destination = [%value.rec "<position>"]
and property_scroll_snap_points_x = [%value.rec
  "'none' | repeat( <length-percentage> )"
]
and property_scroll_snap_points_y = [%value.rec
  "'none' | repeat( <length-percentage> )"
]
and property_scroll_snap_stop = [%value.rec "'normal' | 'always'"]
and property_scroll_snap_type = [%value.rec
  "'none' | [ 'x' | 'y' | 'block' | 'inline' | 'both' ] [ 'mandatory' | 'proximity' ]?"
]
and property_scroll_snap_type_x = [%value.rec
  "'none' | 'mandatory' | 'proximity'"
]
and property_scroll_snap_type_y = [%value.rec
  "'none' | 'mandatory' | 'proximity'"
]
and property_scrollbar_color = [%value.rec
  "'auto' | 'dark' | 'light' | [ <color> ]{2}"
]
and property_scrollbar_width = [%value.rec "'auto' | 'thin' | 'none'"]
and property_shape_image_threshold = [%value.rec "<alpha-value>"]
and property_shape_margin = [%value.rec "<length-percentage>"]
and property_shape_outside = [%value.rec
  "'none' | <shape-box> || <basic-shape> | <image>"
]
and property_tab_size = [%value.rec "<integer> | <length>"]
and property_table_layout = [%value.rec "'auto' | 'fixed'"]
and property_text_align = [%value.rec
  "'start' | 'end' | 'left' | 'right' | 'center' | 'justify' | 'match-parent'"
]
and property_text_align_last = [%value.rec
  "'auto' | 'start' | 'end' | 'left' | 'right' | 'center' | 'justify'"
]
and property_text_combine_upright = [%value.rec
  "'none' | 'all' | 'digits' [ <integer> ]?"
]
and property_text_decoration = [%value.rec
  "<'text-decoration-line'> || <'text-decoration-style'> || <'text-decoration-color'> || <'text-decoration-thickness'>"
]
and property_text_decoration_color = [%value.rec "<color>"]
and property_text_decoration_line = [%value.rec
  "'none' | 'underline' || 'overline' || 'line-through' || 'blink' | 'spelling-error' | 'grammar-error'"
]
and property_text_decoration_skip = [%value.rec
  "'none' | 'objects' || [ 'spaces' | 'leading-spaces' || 'trailing-spaces' ] || 'edges' || 'box-decoration'"
]
and property_text_decoration_skip_ink = [%value.rec "'auto' | 'all' | 'none'"]
and property_text_decoration_style = [%value.rec
  "'solid' | 'double' | 'dotted' | 'dashed' | 'wavy'"
]
and property_text_decoration_thickness = [%value.rec
  "'auto' | 'from-font' | <length> | <percentage>"
]
and property_text_emphasis = [%value.rec
  "<'text-emphasis-style'> || <'text-emphasis-color'>"
]
and property_text_emphasis_color = [%value.rec "<color>"]
and property_text_emphasis_position = [%value.rec
  "[ 'over' | 'under' ] && [ 'right' | 'left' ]"
]
and property_text_emphasis_style = [%value.rec
  "'none' | [ 'filled' | 'open' ] || [ 'dot' | 'circle' | 'double-circle' | 'triangle' | 'sesame' ] | <string>"
]
and property_text_indent = [%value.rec
  "<length-percentage> && [ 'hanging' ]? && [ 'each-line' ]?"
]
and property_text_justify = [%value.rec
  "'auto' | 'inter-character' | 'inter-word' | 'none'"
]
and property_text_orientation = [%value.rec "'mixed' | 'upright' | 'sideways'"]
and property_text_overflow = [%value.rec
  "[ 'clip' | 'ellipsis' | <string> ]{1,2}"
]
and property_text_rendering = [%value.rec
  "'auto' | 'optimizeSpeed' | 'optimizeLegibility' | 'geometricPrecision'"
]
and property_text_shadow = [%value.rec "'none' | [ <shadow-t> ]#"]
and property_text_size_adjust = [%value.rec "'none' | 'auto' | <percentage>"]
and property_text_transform = [%value.rec
  "'none' | 'capitalize' | 'uppercase' | 'lowercase' | 'full-width' | 'full-size-kana'"
]
and property_text_underline_offset = [%value.rec
  "'auto' | <length> | <percentage>"
]
and property_text_underline_position = [%value.rec
  "'auto' | 'from-font' | 'under' || [ 'left' | 'right' ]"
]
and property_top = [%value.rec "<length> | <percentage> | 'auto'"]
and property_touch_action = [%value.rec
  "'auto' | 'none' | [ 'pan-x' | 'pan-left' | 'pan-right' ] || [ 'pan-y' | 'pan-up' | 'pan-down' ] || 'pinch-zoom' | 'manipulation'"
]
and property_transform = [%value.rec "'none' | <transform-list>"]
and property_transform_box = [%value.rec
  "'content-box' | 'border-box' | 'fill-box' | 'stroke-box' | 'view-box'"
]
and property_transform_origin = [%value.rec
  "<length-percentage> | 'left' | 'center' | 'right' | 'top' | 'bottom' | [ [ <length-percentage> | 'left' | 'center' | 'right' ] && [ <length-percentage> | 'top' | 'center' | 'bottom' ] ] [ <length> ]?"
]
and property_transform_style = [%value.rec "'flat' | 'preserve-3d'"]
and property_transition = [%value.rec "[ <single-transition> ]#"]
and property_transition_delay = [%value.rec "[ <time> ]#"]
and property_transition_duration = [%value.rec "[ <time> ]#"]
and property_transition_property = [%value.rec
  "'none' | [ <single-transition-property> ]#"
]
and property_transition_timing_function = [%value.rec "[ <timing-function> ]#"]
and property_translate = [%value.rec
  "'none' | <length-percentage> [ <length-percentage> [ <length> ]? ]?"
]
and property_unicode_bidi = [%value.rec
  "'normal' | 'embed' | 'isolate' | 'bidi-override' | 'isolate-override' | 'plaintext'"
]
and property_user_select = [%value.rec
  "'auto' | 'text' | 'none' | 'contain' | 'all'"
]
and property_vertical_align = [%value.rec
  "'baseline' | 'sub' | 'super' | 'text-top' | 'text-bottom' | 'middle' | 'top' | 'bottom' | <percentage> | <length>"
]
and property_visibility = [%value.rec "'visible' | 'hidden' | 'collapse'"]
and property_white_space = [%value.rec
  "'normal' | 'pre' | 'nowrap' | 'pre-wrap' | 'pre-line' | 'break-spaces'"
]
and property_widows = [%value.rec "<integer>"]
and property_width = [%value.rec
  "'auto' | <length> | <percentage> | 'min-content' | 'max-content' | fit-content( <length-percentage> )"
]
and property_will_change = [%value.rec "'auto' | [ <animateable-feature> ]#"]
and property_word_break = [%value.rec
  "'normal' | 'break-all' | 'keep-all' | 'break-word'"
]
and property_word_spacing = [%value.rec "'normal' | <length-percentage>"]
and property_word_wrap = [%value.rec "'normal' | 'break-word'"]
and property_writing_mode = [%value.rec
  "'horizontal-tb' | 'vertical-rl' | 'vertical-lr' | 'sideways-rl' | 'sideways-lr'"
]
and property_z_index = [%value.rec "'auto' | <integer>"]
and property_zoom = [%value.rec "'normal' | 'reset' | <number> | <percentage>"]
and pseudo_class_selector = [%value.rec
  "':' <ident-token> | ':' <function-token> <any-value> ')'"
]
and pseudo_element_selector = [%value.rec "':' <pseudo-class-selector>"]
and pseudo_page = [%value.rec "':' [ 'left' | 'right' | 'first' | 'blank' ]"]
and quote = [%value.rec
  "'open-quote' | 'close-quote' | 'no-open-quote' | 'no-close-quote'"
]
and relative_selector = [%value.rec "[ <combinator> ]? <complex-selector>"]
and relative_selector_list = [%value.rec "[ <relative-selector> ]#"]
and relative_size = [%value.rec "'larger' | 'smaller'"]
and repeat_style = [%value.rec
  "'repeat-x' | 'repeat-y' | [ 'repeat' | 'space' | 'round' | 'no-repeat' ]{1,2}"
]
and self_position = [%value.rec
  "'center' | 'start' | 'end' | 'self-start' | 'self-end' | 'flex-start' | 'flex-end'"
]
and shadow = [%value.rec "[ 'inset' ]? && [ <length> ]{2,4} && [ <color> ]?"]
and shadow_t = [%value.rec "[ <length> ]{2,3} && [ <color> ]?"]
and shape = [%value.rec
  "rect( <property_top> ',' <property_right> ',' <property_bottom> ',' <property_left> )"
]
and shape_box = [%value.rec "<box> | 'margin-box'"]
and shape_radius = [%value.rec
  "<length-percentage> | 'closest-side' | 'farthest-side'"
]
and side_or_corner = [%value.rec
  "[ 'left' | 'right' ] || [ 'top' | 'bottom' ]"
]
and single_animation = [%value.rec
  "<time> || <timing-function> || <time> || <single-animation-iteration-count> || <single-animation-direction> || <single-animation-fill-mode> || <single-animation-play-state> || [ 'none' | <keyframes-name> ]"
]
and single_animation_direction = [%value.rec
  "'normal' | 'reverse' | 'alternate' | 'alternate-reverse'"
]
and single_animation_fill_mode = [%value.rec
  "'none' | 'forwards' | 'backwards' | 'both'"
]
and single_animation_iteration_count = [%value.rec "'infinite' | <number>"]
and single_animation_play_state = [%value.rec "'running' | 'paused'"]
and single_transition = [%value.rec
  "[ 'none' | <single-transition-property> ] || <time> || <timing-function> || <time>"
]
and single_transition_property = [%value.rec "'all' | <custom-ident>"]
and size = [%value.rec
  "'closest-side' | 'farthest-side' | 'closest-corner' | 'farthest-corner' | <length> | [ <length-percentage> ]{2}"
]
and step_position = [%value.rec
  "'jump-start' | 'jump-end' | 'jump-none' | 'jump-both' | 'start' | 'end'"
]
and step_timing_function = [%value.rec
  "'step-start' | 'step-end' | steps( <integer> [ ',' <step-position> ]? )"
]
and subclass_selector = [%value.rec
  "<id-selector> | <class-selector> | <attribute-selector> | <pseudo-class-selector>"
]
and supports_condition = [%value.rec
  "'not' <supports-in-parens> | <supports-in-parens> [ 'and' <supports-in-parens> ]* | <supports-in-parens> [ 'or' <supports-in-parens> ]*"
]
and supports_decl = [%value.rec "'(' <declaration> ')'"]
and supports_feature = [%value.rec "<supports-decl> | <supports-selector-fn>"]
and supports_in_parens = [%value.rec
  "'(' <supports-condition> ')' | <supports-feature> | <general-enclosed>"
]
and supports_selector_fn = [%value.rec "selector( <complex-selector> )"]
and symbol = [%value.rec "<string> | <image> | <custom-ident>"]
and target = [%value.rec
  "<target-counter()> | <target-counters()> | <target-text()>"
]
and time_percentage = [%value.rec "<time> | <percentage>"]
and timing_function = [%value.rec
  "'linear' | <cubic-bezier-timing-function> | <step-timing-function>"
]
and track_breadth = [%value.rec
  "<length-percentage> | <property_flex> | 'min-content' | 'max-content' | 'auto'"
]
and track_list = [%value.rec
  "[ [ <line-names> ]? [ <track-size> | <track-repeat> ] ]+ [ <line-names> ]?"
]
and track_repeat = [%value.rec
  "repeat( <positive-integer> ',' [ [ <line-names> ]? <track-size> ]+ [ <line-names> ]? )"
]
and track_size = [%value.rec
  "<track-breadth> | minmax( <inflexible-breadth> ',' <track-breadth> ) | fit-content( <length> | <percentage> )"
]
and transform_function = [%value.rec
  "<matrix()> | <translate()> | <translateX()> | <translateY()> | <scale()> | <scaleX()> | <scaleY()> | <rotate()> | <skew()> | <skewX()> | <skewY()> | <matrix3d()> | <translate3d()> | <translateZ()> | <scale3d()> | <scaleZ()> | <rotate3d()> | <rotateX()> | <rotateY()> | <rotateZ()> | <perspective()>"
]
and transform_list = [%value.rec "[ <transform-function> ]+"]
and type_or_unit = [%value.rec
  "'string' | 'color' | 'url' | 'integer' | 'number' | 'length' | 'angle' | 'time' | 'frequency' | 'cap' | 'ch' | 'em' | 'ex' | 'ic' | 'lh' | 'rlh' | 'rem' | 'vb' | 'vi' | 'vw' | 'vh' | 'vmin' | 'vmax' | 'mm' | 'Q' | 'cm' | 'in' | 'pt' | 'pc' | 'px' | 'deg' | 'grad' | 'rad' | 'turn' | 'ms' | 's' | 'Hz' | 'kHz' | '%'"
]
and type_selector = [%value.rec "<wq-name> | [ <ns-prefix> ]? '*'"]
and viewport_length = [%value.rec "'auto' | <length-percentage>"]
and wq_name = [%value.rec "[ <ns-prefix> ]? <ident-token>"];
let check_map =
  StringMap.of_seq(
    List.to_seq([
      ("absolute-size", check(absolute_size)),
      ("alpha-value", check(alpha_value)),
      ("angle-percentage", check(angle_percentage)),
      ("angular-color-hint", check(angular_color_hint)),
      ("angular-color-stop", check(angular_color_stop)),
      ("angular-color-stop-list", check(angular_color_stop_list)),
      ("animateable-feature", check(animateable_feature)),
      ("attachment", check(attachment)),
      ("attr-matcher", check(attr_matcher)),
      ("attr-modifier", check(attr_modifier)),
      ("attribute-selector", check(attribute_selector)),
      ("auto-repeat", check(auto_repeat)),
      ("auto-track-list", check(auto_track_list)),
      ("baseline-position", check(baseline_position)),
      ("basic-shape", check(basic_shape)),
      ("bg-image", check(bg_image)),
      ("bg-layer", check(bg_layer)),
      ("bg-position", check(bg_position)),
      ("bg-size", check(bg_size)),
      ("blend-mode", check(blend_mode)),
      ("box", check(box)),
      ("calc-product", check(calc_product)),
      ("calc-sum", check(calc_sum)),
      ("calc-value", check(calc_value)),
      ("cf-final-image", check(cf_final_image)),
      ("cf-mixing-image", check(cf_mixing_image)),
      ("class-selector", check(class_selector)),
      ("clip-source", check(clip_source)),
      ("color", check(color)),
      ("color-stop", check(color_stop)),
      ("color-stop-angle", check(color_stop_angle)),
      ("color-stop-length", check(color_stop_length)),
      ("color-stop-list", check(color_stop_list)),
      ("combinator", check(combinator)),
      ("common-lig-values", check(common_lig_values)),
      ("compat-auto", check(compat_auto)),
      ("complex-selector", check(complex_selector)),
      ("complex-selector-list", check(complex_selector_list)),
      ("composite-style", check(composite_style)),
      ("compositing-operator", check(compositing_operator)),
      ("compound-selector", check(compound_selector)),
      ("compound-selector-list", check(compound_selector_list)),
      ("content-distribution", check(content_distribution)),
      ("content-list", check(content_list)),
      ("content-position", check(content_position)),
      ("content-replacement", check(content_replacement)),
      ("contextual-alt-values", check(contextual_alt_values)),
      ("counter-style", check(counter_style)),
      ("counter-style-name", check(counter_style_name)),
      ("cubic-bezier-timing-function", check(cubic_bezier_timing_function)),
      ("deprecated-system-color", check(deprecated_system_color)),
      ("discretionary-lig-values", check(discretionary_lig_values)),
      ("display-box", check(display_box)),
      ("display-inside", check(display_inside)),
      ("display-internal", check(display_internal)),
      ("display-legacy", check(display_legacy)),
      ("display-listitem", check(display_listitem)),
      ("display-outside", check(display_outside)),
      ("east-asian-variant-values", check(east_asian_variant_values)),
      ("east-asian-width-values", check(east_asian_width_values)),
      ("ending-shape", check(ending_shape)),
      ("explicit-track-list", check(explicit_track_list)),
      ("family-name", check(family_name)),
      ("feature-tag-value", check(feature_tag_value)),
      ("feature-type", check(feature_type)),
      ("feature-value-block", check(feature_value_block)),
      ("feature-value-block-list", check(feature_value_block_list)),
      ("feature-value-declaration", check(feature_value_declaration)),
      (
        "feature-value-declaration-list",
        check(feature_value_declaration_list),
      ),
      ("feature-value-name", check(feature_value_name)),
      ("fill-rule", check(fill_rule)),
      ("filter-function", check(filter_function)),
      ("filter-function-list", check(filter_function_list)),
      ("final-bg-layer", check(final_bg_layer)),
      ("fixed-breadth", check(fixed_breadth)),
      ("fixed-repeat", check(fixed_repeat)),
      ("fixed-size", check(fixed_size)),
      ("font-stretch-absolute", check(font_stretch_absolute)),
      ("font-variant-css21", check(font_variant_css21)),
      ("font-weight-absolute", check(font_weight_absolute)),
      ("frequency-percentage", check(frequency_percentage)),
      ("function_attr", check(function_attr)),
      ("function_blur", check(function_blur)),
      ("function_brightness", check(function_brightness)),
      ("function_calc", check(function_calc)),
      ("function_circle", check(function_circle)),
      ("function_clamp", check(function_clamp)),
      ("function_conic-gradient", check(function_conic_gradient)),
      ("function_contrast", check(function_contrast)),
      ("function_counter", check(function_counter)),
      ("function_counters", check(function_counters)),
      ("function_cross-fade", check(function_cross_fade)),
      ("function_drop-shadow", check(function_drop_shadow)),
      ("function_element", check(function_element)),
      ("function_ellipse", check(function_ellipse)),
      ("function_env", check(function_env)),
      ("function_fit-content", check(function_fit_content)),
      ("function_grayscale", check(function_grayscale)),
      ("function_hsl", check(function_hsl)),
      ("function_hsla", check(function_hsla)),
      ("function_hue-rotate", check(function_hue_rotate)),
      ("function_image", check(function_image)),
      ("function_image-set", check(function_image_set)),
      ("function_inset", check(function_inset)),
      ("function_invert", check(function_invert)),
      ("function_leader", check(function_leader)),
      ("function_linear-gradient", check(function_linear_gradient)),
      ("function_matrix", check(function_matrix)),
      ("function_matrix3d", check(function_matrix3d)),
      ("function_max", check(function_max)),
      ("function_min", check(function_min)),
      ("function_minmax", check(function_minmax)),
      ("function_opacity", check(function_opacity)),
      ("function_paint", check(function_paint)),
      ("function_path", check(function_path)),
      ("function_perspective", check(function_perspective)),
      ("function_polygon", check(function_polygon)),
      ("function_radial-gradient", check(function_radial_gradient)),
      (
        "function_repeating-linear-gradient",
        check(function_repeating_linear_gradient),
      ),
      (
        "function_repeating-radial-gradient",
        check(function_repeating_radial_gradient),
      ),
      ("function_rgb", check(function_rgb)),
      ("function_rgba", check(function_rgba)),
      ("function_rotate", check(function_rotate)),
      ("function_rotate3d", check(function_rotate3d)),
      ("function_rotateX", check(function_rotateX)),
      ("function_rotateY", check(function_rotateY)),
      ("function_rotateZ", check(function_rotateZ)),
      ("function_saturate", check(function_saturate)),
      ("function_scale", check(function_scale)),
      ("function_scale3d", check(function_scale3d)),
      ("function_scaleX", check(function_scaleX)),
      ("function_scaleY", check(function_scaleY)),
      ("function_scaleZ", check(function_scaleZ)),
      ("function_sepia", check(function_sepia)),
      ("function_skew", check(function_skew)),
      ("function_skewX", check(function_skewX)),
      ("function_skewY", check(function_skewY)),
      ("function_target-counter", check(function_target_counter)),
      ("function_target-counters", check(function_target_counters)),
      ("function_target-text", check(function_target_text)),
      ("function_translate", check(function_translate)),
      ("function_translate3d", check(function_translate3d)),
      ("function_translateX", check(function_translateX)),
      ("function_translateY", check(function_translateY)),
      ("function_translateZ", check(function_translateZ)),
      ("function_var", check(function_var)),
      ("general-enclosed", check(general_enclosed)),
      ("generic-family", check(generic_family)),
      ("generic-name", check(generic_name)),
      ("geometry-box", check(geometry_box)),
      ("gradient", check(gradient)),
      ("grid-line", check(grid_line)),
      ("historical-lig-values", check(historical_lig_values)),
      ("hue", check(hue)),
      ("id-selector", check(id_selector)),
      ("image", check(image)),
      ("image-set-option", check(image_set_option)),
      ("image-src", check(image_src)),
      ("image-tags", check(image_tags)),
      ("inflexible-breadth", check(inflexible_breadth)),
      ("keyframe-block", check(keyframe_block)),
      ("keyframe-block-list", check(keyframe_block_list)),
      ("keyframe-selector", check(keyframe_selector)),
      ("keyframes-name", check(keyframes_name)),
      ("leader-type", check(leader_type)),
      ("length-percentage", check(length_percentage)),
      ("line-name-list", check(line_name_list)),
      ("line-names", check(line_names)),
      ("line-style", check(line_style)),
      ("line-width", check(line_width)),
      ("linear-color-hint", check(linear_color_hint)),
      ("linear-color-stop", check(linear_color_stop)),
      ("mask-layer", check(mask_layer)),
      ("mask-position", check(mask_position)),
      ("mask-reference", check(mask_reference)),
      ("mask-source", check(mask_source)),
      ("masking-mode", check(masking_mode)),
      ("media-and", check(media_and)),
      ("media-condition", check(media_condition)),
      ("media-condition-without-or", check(media_condition_without_or)),
      ("media-feature", check(media_feature)),
      ("media-in-parens", check(media_in_parens)),
      ("media-not", check(media_not)),
      ("media-or", check(media_or)),
      ("media-query", check(media_query)),
      ("media-query-list", check(media_query_list)),
      ("media-type", check(media_type)),
      ("mf-boolean", check(mf_boolean)),
      ("mf-name", check(mf_name)),
      ("mf-plain", check(mf_plain)),
      ("mf-range", check(mf_range)),
      ("mf-value", check(mf_value)),
      ("named-color", check(named_color)),
      ("namespace-prefix", check(namespace_prefix)),
      ("ns-prefix", check(ns_prefix)),
      ("nth", check(nth)),
      ("number-percentage", check(number_percentage)),
      ("numeric-figure-values", check(numeric_figure_values)),
      ("numeric-fraction-values", check(numeric_fraction_values)),
      ("numeric-spacing-values", check(numeric_spacing_values)),
      ("outline-radius", check(outline_radius)),
      ("overflow-position", check(overflow_position)),
      ("page-body", check(page_body)),
      ("page-margin-box", check(page_margin_box)),
      ("page-margin-box-type", check(page_margin_box_type)),
      ("page-selector", check(page_selector)),
      ("page-selector-list", check(page_selector_list)),
      ("position", check(position)),
      ("property_-moz-appearance", check(property__moz_appearance)),
      ("property_-moz-binding", check(property__moz_binding)),
      (
        "property_-moz-border-bottom-colors",
        check(property__moz_border_bottom_colors),
      ),
      (
        "property_-moz-border-left-colors",
        check(property__moz_border_left_colors),
      ),
      (
        "property_-moz-border-right-colors",
        check(property__moz_border_right_colors),
      ),
      (
        "property_-moz-border-top-colors",
        check(property__moz_border_top_colors),
      ),
      (
        "property_-moz-context-properties",
        check(property__moz_context_properties),
      ),
      ("property_-moz-float-edge", check(property__moz_float_edge)),
      (
        "property_-moz-force-broken-image-icon",
        check(property__moz_force_broken_image_icon),
      ),
      ("property_-moz-image-region", check(property__moz_image_region)),
      ("property_-moz-orient", check(property__moz_orient)),
      ("property_-moz-outline-radius", check(property__moz_outline_radius)),
      (
        "property_-moz-outline-radius-bottomleft",
        check(property__moz_outline_radius_bottomleft),
      ),
      (
        "property_-moz-outline-radius-bottomright",
        check(property__moz_outline_radius_bottomright),
      ),
      (
        "property_-moz-outline-radius-topleft",
        check(property__moz_outline_radius_topleft),
      ),
      (
        "property_-moz-outline-radius-topright",
        check(property__moz_outline_radius_topright),
      ),
      ("property_-moz-stack-sizing", check(property__moz_stack_sizing)),
      ("property_-moz-text-blink", check(property__moz_text_blink)),
      ("property_-moz-user-focus", check(property__moz_user_focus)),
      ("property_-moz-user-input", check(property__moz_user_input)),
      ("property_-moz-user-modify", check(property__moz_user_modify)),
      (
        "property_-moz-window-dragging",
        check(property__moz_window_dragging),
      ),
      ("property_-moz-window-shadow", check(property__moz_window_shadow)),
      ("property_-ms-accelerator", check(property__ms_accelerator)),
      (
        "property_-ms-block-progression",
        check(property__ms_block_progression),
      ),
      (
        "property_-ms-content-zoom-chaining",
        check(property__ms_content_zoom_chaining),
      ),
      (
        "property_-ms-content-zoom-limit",
        check(property__ms_content_zoom_limit),
      ),
      (
        "property_-ms-content-zoom-limit-max",
        check(property__ms_content_zoom_limit_max),
      ),
      (
        "property_-ms-content-zoom-limit-min",
        check(property__ms_content_zoom_limit_min),
      ),
      (
        "property_-ms-content-zoom-snap",
        check(property__ms_content_zoom_snap),
      ),
      (
        "property_-ms-content-zoom-snap-points",
        check(property__ms_content_zoom_snap_points),
      ),
      (
        "property_-ms-content-zoom-snap-type",
        check(property__ms_content_zoom_snap_type),
      ),
      ("property_-ms-content-zooming", check(property__ms_content_zooming)),
      ("property_-ms-filter", check(property__ms_filter)),
      ("property_-ms-flow-from", check(property__ms_flow_from)),
      ("property_-ms-flow-into", check(property__ms_flow_into)),
      (
        "property_-ms-high-contrast-adjust",
        check(property__ms_high_contrast_adjust),
      ),
      (
        "property_-ms-hyphenate-limit-chars",
        check(property__ms_hyphenate_limit_chars),
      ),
      (
        "property_-ms-hyphenate-limit-lines",
        check(property__ms_hyphenate_limit_lines),
      ),
      (
        "property_-ms-hyphenate-limit-zone",
        check(property__ms_hyphenate_limit_zone),
      ),
      ("property_-ms-ime-align", check(property__ms_ime_align)),
      ("property_-ms-overflow-style", check(property__ms_overflow_style)),
      ("property_-ms-scroll-chaining", check(property__ms_scroll_chaining)),
      ("property_-ms-scroll-limit", check(property__ms_scroll_limit)),
      (
        "property_-ms-scroll-limit-x-max",
        check(property__ms_scroll_limit_x_max),
      ),
      (
        "property_-ms-scroll-limit-x-min",
        check(property__ms_scroll_limit_x_min),
      ),
      (
        "property_-ms-scroll-limit-y-max",
        check(property__ms_scroll_limit_y_max),
      ),
      (
        "property_-ms-scroll-limit-y-min",
        check(property__ms_scroll_limit_y_min),
      ),
      ("property_-ms-scroll-rails", check(property__ms_scroll_rails)),
      (
        "property_-ms-scroll-snap-points-x",
        check(property__ms_scroll_snap_points_x),
      ),
      (
        "property_-ms-scroll-snap-points-y",
        check(property__ms_scroll_snap_points_y),
      ),
      (
        "property_-ms-scroll-snap-type",
        check(property__ms_scroll_snap_type),
      ),
      ("property_-ms-scroll-snap-x", check(property__ms_scroll_snap_x)),
      ("property_-ms-scroll-snap-y", check(property__ms_scroll_snap_y)),
      (
        "property_-ms-scroll-translation",
        check(property__ms_scroll_translation),
      ),
      (
        "property_-ms-scrollbar-3dlight-color",
        check(property__ms_scrollbar_3dlight_color),
      ),
      (
        "property_-ms-scrollbar-arrow-color",
        check(property__ms_scrollbar_arrow_color),
      ),
      (
        "property_-ms-scrollbar-base-color",
        check(property__ms_scrollbar_base_color),
      ),
      (
        "property_-ms-scrollbar-darkshadow-color",
        check(property__ms_scrollbar_darkshadow_color),
      ),
      (
        "property_-ms-scrollbar-face-color",
        check(property__ms_scrollbar_face_color),
      ),
      (
        "property_-ms-scrollbar-highlight-color",
        check(property__ms_scrollbar_highlight_color),
      ),
      (
        "property_-ms-scrollbar-shadow-color",
        check(property__ms_scrollbar_shadow_color),
      ),
      (
        "property_-ms-scrollbar-track-color",
        check(property__ms_scrollbar_track_color),
      ),
      ("property_-ms-text-autospace", check(property__ms_text_autospace)),
      ("property_-ms-touch-select", check(property__ms_touch_select)),
      ("property_-ms-user-select", check(property__ms_user_select)),
      ("property_-ms-wrap-flow", check(property__ms_wrap_flow)),
      ("property_-ms-wrap-margin", check(property__ms_wrap_margin)),
      ("property_-ms-wrap-through", check(property__ms_wrap_through)),
      ("property_-webkit-appearance", check(property__webkit_appearance)),
      (
        "property_-webkit-border-before",
        check(property__webkit_border_before),
      ),
      (
        "property_-webkit-border-before-color",
        check(property__webkit_border_before_color),
      ),
      (
        "property_-webkit-border-before-style",
        check(property__webkit_border_before_style),
      ),
      (
        "property_-webkit-border-before-width",
        check(property__webkit_border_before_width),
      ),
      ("property_-webkit-box-reflect", check(property__webkit_box_reflect)),
      ("property_-webkit-line-clamp", check(property__webkit_line_clamp)),
      ("property_-webkit-mask", check(property__webkit_mask)),
      (
        "property_-webkit-mask-attachment",
        check(property__webkit_mask_attachment),
      ),
      ("property_-webkit-mask-clip", check(property__webkit_mask_clip)),
      (
        "property_-webkit-mask-composite",
        check(property__webkit_mask_composite),
      ),
      ("property_-webkit-mask-image", check(property__webkit_mask_image)),
      ("property_-webkit-mask-origin", check(property__webkit_mask_origin)),
      (
        "property_-webkit-mask-position",
        check(property__webkit_mask_position),
      ),
      (
        "property_-webkit-mask-position-x",
        check(property__webkit_mask_position_x),
      ),
      (
        "property_-webkit-mask-position-y",
        check(property__webkit_mask_position_y),
      ),
      ("property_-webkit-mask-repeat", check(property__webkit_mask_repeat)),
      (
        "property_-webkit-mask-repeat-x",
        check(property__webkit_mask_repeat_x),
      ),
      (
        "property_-webkit-mask-repeat-y",
        check(property__webkit_mask_repeat_y),
      ),
      ("property_-webkit-mask-size", check(property__webkit_mask_size)),
      (
        "property_-webkit-overflow-scrolling",
        check(property__webkit_overflow_scrolling),
      ),
      (
        "property_-webkit-tap-highlight-color",
        check(property__webkit_tap_highlight_color),
      ),
      (
        "property_-webkit-text-fill-color",
        check(property__webkit_text_fill_color),
      ),
      ("property_-webkit-text-stroke", check(property__webkit_text_stroke)),
      (
        "property_-webkit-text-stroke-color",
        check(property__webkit_text_stroke_color),
      ),
      (
        "property_-webkit-text-stroke-width",
        check(property__webkit_text_stroke_width),
      ),
      (
        "property_-webkit-touch-callout",
        check(property__webkit_touch_callout),
      ),
      ("property_-webkit-user-modify", check(property__webkit_user_modify)),
      ("property_align-content", check(property_align_content)),
      ("property_align-items", check(property_align_items)),
      ("property_align-self", check(property_align_self)),
      ("property_all", check(property_all)),
      ("property_animation", check(property_animation)),
      ("property_animation-delay", check(property_animation_delay)),
      ("property_animation-direction", check(property_animation_direction)),
      ("property_animation-duration", check(property_animation_duration)),
      ("property_animation-fill-mode", check(property_animation_fill_mode)),
      (
        "property_animation-iteration-count",
        check(property_animation_iteration_count),
      ),
      ("property_animation-name", check(property_animation_name)),
      (
        "property_animation-play-state",
        check(property_animation_play_state),
      ),
      (
        "property_animation-timing-function",
        check(property_animation_timing_function),
      ),
      ("property_appearance", check(property_appearance)),
      ("property_aspect-ratio", check(property_aspect_ratio)),
      ("property_azimuth", check(property_azimuth)),
      ("property_backdrop-filter", check(property_backdrop_filter)),
      ("property_backface-visibility", check(property_backface_visibility)),
      ("property_background", check(property_background)),
      (
        "property_background-attachment",
        check(property_background_attachment),
      ),
      (
        "property_background-blend-mode",
        check(property_background_blend_mode),
      ),
      ("property_background-clip", check(property_background_clip)),
      ("property_background-color", check(property_background_color)),
      ("property_background-image", check(property_background_image)),
      ("property_background-origin", check(property_background_origin)),
      ("property_background-position", check(property_background_position)),
      (
        "property_background-position-x",
        check(property_background_position_x),
      ),
      (
        "property_background-position-y",
        check(property_background_position_y),
      ),
      ("property_background-repeat", check(property_background_repeat)),
      ("property_background-size", check(property_background_size)),
      ("property_block-overflow", check(property_block_overflow)),
      ("property_block-size", check(property_block_size)),
      ("property_border", check(property_border)),
      ("property_border-block", check(property_border_block)),
      ("property_border-block-color", check(property_border_block_color)),
      ("property_border-block-end", check(property_border_block_end)),
      (
        "property_border-block-end-color",
        check(property_border_block_end_color),
      ),
      (
        "property_border-block-end-style",
        check(property_border_block_end_style),
      ),
      (
        "property_border-block-end-width",
        check(property_border_block_end_width),
      ),
      ("property_border-block-start", check(property_border_block_start)),
      (
        "property_border-block-start-color",
        check(property_border_block_start_color),
      ),
      (
        "property_border-block-start-style",
        check(property_border_block_start_style),
      ),
      (
        "property_border-block-start-width",
        check(property_border_block_start_width),
      ),
      ("property_border-block-style", check(property_border_block_style)),
      ("property_border-block-width", check(property_border_block_width)),
      ("property_border-bottom", check(property_border_bottom)),
      ("property_border-bottom-color", check(property_border_bottom_color)),
      (
        "property_border-bottom-left-radius",
        check(property_border_bottom_left_radius),
      ),
      (
        "property_border-bottom-right-radius",
        check(property_border_bottom_right_radius),
      ),
      ("property_border-bottom-style", check(property_border_bottom_style)),
      ("property_border-bottom-width", check(property_border_bottom_width)),
      ("property_border-collapse", check(property_border_collapse)),
      ("property_border-color", check(property_border_color)),
      (
        "property_border-end-end-radius",
        check(property_border_end_end_radius),
      ),
      (
        "property_border-end-start-radius",
        check(property_border_end_start_radius),
      ),
      ("property_border-image", check(property_border_image)),
      ("property_border-image-outset", check(property_border_image_outset)),
      ("property_border-image-repeat", check(property_border_image_repeat)),
      ("property_border-image-slice", check(property_border_image_slice)),
      ("property_border-image-source", check(property_border_image_source)),
      ("property_border-image-width", check(property_border_image_width)),
      ("property_border-inline", check(property_border_inline)),
      ("property_border-inline-color", check(property_border_inline_color)),
      ("property_border-inline-end", check(property_border_inline_end)),
      (
        "property_border-inline-end-color",
        check(property_border_inline_end_color),
      ),
      (
        "property_border-inline-end-style",
        check(property_border_inline_end_style),
      ),
      (
        "property_border-inline-end-width",
        check(property_border_inline_end_width),
      ),
      ("property_border-inline-start", check(property_border_inline_start)),
      (
        "property_border-inline-start-color",
        check(property_border_inline_start_color),
      ),
      (
        "property_border-inline-start-style",
        check(property_border_inline_start_style),
      ),
      (
        "property_border-inline-start-width",
        check(property_border_inline_start_width),
      ),
      ("property_border-inline-style", check(property_border_inline_style)),
      ("property_border-inline-width", check(property_border_inline_width)),
      ("property_border-left", check(property_border_left)),
      ("property_border-left-color", check(property_border_left_color)),
      ("property_border-left-style", check(property_border_left_style)),
      ("property_border-left-width", check(property_border_left_width)),
      ("property_border-radius", check(property_border_radius)),
      ("property_border-right", check(property_border_right)),
      ("property_border-right-color", check(property_border_right_color)),
      ("property_border-right-style", check(property_border_right_style)),
      ("property_border-right-width", check(property_border_right_width)),
      ("property_border-spacing", check(property_border_spacing)),
      (
        "property_border-start-end-radius",
        check(property_border_start_end_radius),
      ),
      (
        "property_border-start-start-radius",
        check(property_border_start_start_radius),
      ),
      ("property_border-style", check(property_border_style)),
      ("property_border-top", check(property_border_top)),
      ("property_border-top-color", check(property_border_top_color)),
      (
        "property_border-top-left-radius",
        check(property_border_top_left_radius),
      ),
      (
        "property_border-top-right-radius",
        check(property_border_top_right_radius),
      ),
      ("property_border-top-style", check(property_border_top_style)),
      ("property_border-top-width", check(property_border_top_width)),
      ("property_border-width", check(property_border_width)),
      ("property_bottom", check(property_bottom)),
      ("property_box-align", check(property_box_align)),
      (
        "property_box-decoration-break",
        check(property_box_decoration_break),
      ),
      ("property_box-direction", check(property_box_direction)),
      ("property_box-flex", check(property_box_flex)),
      ("property_box-flex-group", check(property_box_flex_group)),
      ("property_box-lines", check(property_box_lines)),
      ("property_box-ordinal-group", check(property_box_ordinal_group)),
      ("property_box-orient", check(property_box_orient)),
      ("property_box-pack", check(property_box_pack)),
      ("property_box-shadow", check(property_box_shadow)),
      ("property_box-sizing", check(property_box_sizing)),
      ("property_break-after", check(property_break_after)),
      ("property_break-before", check(property_break_before)),
      ("property_break-inside", check(property_break_inside)),
      ("property_caption-side", check(property_caption_side)),
      ("property_caret-color", check(property_caret_color)),
      ("property_clear", check(property_clear)),
      ("property_clip", check(property_clip)),
      ("property_clip-path", check(property_clip_path)),
      ("property_color", check(property_color)),
      ("property_color-adjust", check(property_color_adjust)),
      ("property_column-count", check(property_column_count)),
      ("property_column-fill", check(property_column_fill)),
      ("property_column-gap", check(property_column_gap)),
      ("property_column-rule", check(property_column_rule)),
      ("property_column-rule-color", check(property_column_rule_color)),
      ("property_column-rule-style", check(property_column_rule_style)),
      ("property_column-rule-width", check(property_column_rule_width)),
      ("property_column-span", check(property_column_span)),
      ("property_column-width", check(property_column_width)),
      ("property_columns", check(property_columns)),
      ("property_contain", check(property_contain)),
      ("property_content", check(property_content)),
      ("property_counter-increment", check(property_counter_increment)),
      ("property_counter-reset", check(property_counter_reset)),
      ("property_counter-set", check(property_counter_set)),
      ("property_cursor", check(property_cursor)),
      ("property_direction", check(property_direction)),
      ("property_display", check(property_display)),
      ("property_empty-cells", check(property_empty_cells)),
      ("property_filter", check(property_filter)),
      ("property_flex", check(property_flex)),
      ("property_flex-basis", check(property_flex_basis)),
      ("property_flex-direction", check(property_flex_direction)),
      ("property_flex-flow", check(property_flex_flow)),
      ("property_flex-grow", check(property_flex_grow)),
      ("property_flex-shrink", check(property_flex_shrink)),
      ("property_flex-wrap", check(property_flex_wrap)),
      ("property_float", check(property_float)),
      ("property_font", check(property_font)),
      ("property_font-family", check(property_font_family)),
      (
        "property_font-feature-settings",
        check(property_font_feature_settings),
      ),
      ("property_font-kerning", check(property_font_kerning)),
      (
        "property_font-language-override",
        check(property_font_language_override),
      ),
      ("property_font-optical-sizing", check(property_font_optical_sizing)),
      ("property_font-size", check(property_font_size)),
      ("property_font-size-adjust", check(property_font_size_adjust)),
      ("property_font-smooth", check(property_font_smooth)),
      ("property_font-stretch", check(property_font_stretch)),
      ("property_font-style", check(property_font_style)),
      ("property_font-synthesis", check(property_font_synthesis)),
      ("property_font-variant", check(property_font_variant)),
      (
        "property_font-variant-alternates",
        check(property_font_variant_alternates),
      ),
      ("property_font-variant-caps", check(property_font_variant_caps)),
      (
        "property_font-variant-east-asian",
        check(property_font_variant_east_asian),
      ),
      (
        "property_font-variant-ligatures",
        check(property_font_variant_ligatures),
      ),
      (
        "property_font-variant-numeric",
        check(property_font_variant_numeric),
      ),
      (
        "property_font-variant-position",
        check(property_font_variant_position),
      ),
      (
        "property_font-variation-settings",
        check(property_font_variation_settings),
      ),
      ("property_font-weight", check(property_font_weight)),
      ("property_gap", check(property_gap)),
      ("property_grid", check(property_grid)),
      ("property_grid-area", check(property_grid_area)),
      ("property_grid-auto-columns", check(property_grid_auto_columns)),
      ("property_grid-auto-flow", check(property_grid_auto_flow)),
      ("property_grid-auto-rows", check(property_grid_auto_rows)),
      ("property_grid-column", check(property_grid_column)),
      ("property_grid-column-end", check(property_grid_column_end)),
      ("property_grid-column-gap", check(property_grid_column_gap)),
      ("property_grid-column-start", check(property_grid_column_start)),
      ("property_grid-gap", check(property_grid_gap)),
      ("property_grid-row", check(property_grid_row)),
      ("property_grid-row-end", check(property_grid_row_end)),
      ("property_grid-row-gap", check(property_grid_row_gap)),
      ("property_grid-row-start", check(property_grid_row_start)),
      ("property_grid-template", check(property_grid_template)),
      ("property_grid-template-areas", check(property_grid_template_areas)),
      (
        "property_grid-template-columns",
        check(property_grid_template_columns),
      ),
      ("property_grid-template-rows", check(property_grid_template_rows)),
      ("property_hanging-punctuation", check(property_hanging_punctuation)),
      ("property_height", check(property_height)),
      ("property_hyphens", check(property_hyphens)),
      ("property_image-orientation", check(property_image_orientation)),
      ("property_image-rendering", check(property_image_rendering)),
      ("property_image-resolution", check(property_image_resolution)),
      ("property_ime-mode", check(property_ime_mode)),
      ("property_initial-letter", check(property_initial_letter)),
      (
        "property_initial-letter-align",
        check(property_initial_letter_align),
      ),
      ("property_inline-size", check(property_inline_size)),
      ("property_inset", check(property_inset)),
      ("property_inset-block", check(property_inset_block)),
      ("property_inset-block-end", check(property_inset_block_end)),
      ("property_inset-block-start", check(property_inset_block_start)),
      ("property_inset-inline", check(property_inset_inline)),
      ("property_inset-inline-end", check(property_inset_inline_end)),
      ("property_inset-inline-start", check(property_inset_inline_start)),
      ("property_isolation", check(property_isolation)),
      ("property_justify-content", check(property_justify_content)),
      ("property_justify-items", check(property_justify_items)),
      ("property_justify-self", check(property_justify_self)),
      ("property_left", check(property_left)),
      ("property_letter-spacing", check(property_letter_spacing)),
      ("property_line-break", check(property_line_break)),
      ("property_line-clamp", check(property_line_clamp)),
      ("property_line-height", check(property_line_height)),
      ("property_line-height-step", check(property_line_height_step)),
      ("property_list-style", check(property_list_style)),
      ("property_list-style-image", check(property_list_style_image)),
      ("property_list-style-position", check(property_list_style_position)),
      ("property_list-style-type", check(property_list_style_type)),
      ("property_margin", check(property_margin)),
      ("property_margin-block", check(property_margin_block)),
      ("property_margin-block-end", check(property_margin_block_end)),
      ("property_margin-block-start", check(property_margin_block_start)),
      ("property_margin-bottom", check(property_margin_bottom)),
      ("property_margin-inline", check(property_margin_inline)),
      ("property_margin-inline-end", check(property_margin_inline_end)),
      ("property_margin-inline-start", check(property_margin_inline_start)),
      ("property_margin-left", check(property_margin_left)),
      ("property_margin-right", check(property_margin_right)),
      ("property_margin-top", check(property_margin_top)),
      ("property_margin-trim", check(property_margin_trim)),
      ("property_mask", check(property_mask)),
      ("property_mask-border", check(property_mask_border)),
      ("property_mask-border-mode", check(property_mask_border_mode)),
      ("property_mask-border-outset", check(property_mask_border_outset)),
      ("property_mask-border-repeat", check(property_mask_border_repeat)),
      ("property_mask-border-slice", check(property_mask_border_slice)),
      ("property_mask-border-source", check(property_mask_border_source)),
      ("property_mask-border-width", check(property_mask_border_width)),
      ("property_mask-clip", check(property_mask_clip)),
      ("property_mask-composite", check(property_mask_composite)),
      ("property_mask-image", check(property_mask_image)),
      ("property_mask-mode", check(property_mask_mode)),
      ("property_mask-origin", check(property_mask_origin)),
      ("property_mask-position", check(property_mask_position)),
      ("property_mask-repeat", check(property_mask_repeat)),
      ("property_mask-size", check(property_mask_size)),
      ("property_mask-type", check(property_mask_type)),
      ("property_max-block-size", check(property_max_block_size)),
      ("property_max-height", check(property_max_height)),
      ("property_max-inline-size", check(property_max_inline_size)),
      ("property_max-lines", check(property_max_lines)),
      ("property_max-width", check(property_max_width)),
      ("property_min-block-size", check(property_min_block_size)),
      ("property_min-height", check(property_min_height)),
      ("property_min-inline-size", check(property_min_inline_size)),
      ("property_min-width", check(property_min_width)),
      ("property_mix-blend-mode", check(property_mix_blend_mode)),
      ("property_object-fit", check(property_object_fit)),
      ("property_object-position", check(property_object_position)),
      ("property_offset", check(property_offset)),
      ("property_offset-anchor", check(property_offset_anchor)),
      ("property_offset-distance", check(property_offset_distance)),
      ("property_offset-path", check(property_offset_path)),
      ("property_offset-position", check(property_offset_position)),
      ("property_offset-rotate", check(property_offset_rotate)),
      ("property_opacity", check(property_opacity)),
      ("property_order", check(property_order)),
      ("property_orphans", check(property_orphans)),
      ("property_outline", check(property_outline)),
      ("property_outline-color", check(property_outline_color)),
      ("property_outline-offset", check(property_outline_offset)),
      ("property_outline-style", check(property_outline_style)),
      ("property_outline-width", check(property_outline_width)),
      ("property_overflow", check(property_overflow)),
      ("property_overflow-anchor", check(property_overflow_anchor)),
      ("property_overflow-block", check(property_overflow_block)),
      ("property_overflow-clip-box", check(property_overflow_clip_box)),
      ("property_overflow-inline", check(property_overflow_inline)),
      ("property_overflow-wrap", check(property_overflow_wrap)),
      ("property_overflow-x", check(property_overflow_x)),
      ("property_overflow-y", check(property_overflow_y)),
      ("property_overscroll-behavior", check(property_overscroll_behavior)),
      (
        "property_overscroll-behavior-block",
        check(property_overscroll_behavior_block),
      ),
      (
        "property_overscroll-behavior-inline",
        check(property_overscroll_behavior_inline),
      ),
      (
        "property_overscroll-behavior-x",
        check(property_overscroll_behavior_x),
      ),
      (
        "property_overscroll-behavior-y",
        check(property_overscroll_behavior_y),
      ),
      ("property_padding", check(property_padding)),
      ("property_padding-block", check(property_padding_block)),
      ("property_padding-block-end", check(property_padding_block_end)),
      ("property_padding-block-start", check(property_padding_block_start)),
      ("property_padding-bottom", check(property_padding_bottom)),
      ("property_padding-inline", check(property_padding_inline)),
      ("property_padding-inline-end", check(property_padding_inline_end)),
      (
        "property_padding-inline-start",
        check(property_padding_inline_start),
      ),
      ("property_padding-left", check(property_padding_left)),
      ("property_padding-right", check(property_padding_right)),
      ("property_padding-top", check(property_padding_top)),
      ("property_page-break-after", check(property_page_break_after)),
      ("property_page-break-before", check(property_page_break_before)),
      ("property_page-break-inside", check(property_page_break_inside)),
      ("property_paint-order", check(property_paint_order)),
      ("property_perspective", check(property_perspective)),
      ("property_perspective-origin", check(property_perspective_origin)),
      ("property_place-content", check(property_place_content)),
      ("property_place-items", check(property_place_items)),
      ("property_place-self", check(property_place_self)),
      ("property_pointer-events", check(property_pointer_events)),
      ("property_position", check(property_position)),
      ("property_quotes", check(property_quotes)),
      ("property_resize", check(property_resize)),
      ("property_right", check(property_right)),
      ("property_rotate", check(property_rotate)),
      ("property_row-gap", check(property_row_gap)),
      ("property_ruby-align", check(property_ruby_align)),
      ("property_ruby-merge", check(property_ruby_merge)),
      ("property_ruby-position", check(property_ruby_position)),
      ("property_scale", check(property_scale)),
      ("property_scroll-behavior", check(property_scroll_behavior)),
      ("property_scroll-margin", check(property_scroll_margin)),
      ("property_scroll-margin-block", check(property_scroll_margin_block)),
      (
        "property_scroll-margin-block-end",
        check(property_scroll_margin_block_end),
      ),
      (
        "property_scroll-margin-block-start",
        check(property_scroll_margin_block_start),
      ),
      (
        "property_scroll-margin-bottom",
        check(property_scroll_margin_bottom),
      ),
      (
        "property_scroll-margin-inline",
        check(property_scroll_margin_inline),
      ),
      (
        "property_scroll-margin-inline-end",
        check(property_scroll_margin_inline_end),
      ),
      (
        "property_scroll-margin-inline-start",
        check(property_scroll_margin_inline_start),
      ),
      ("property_scroll-margin-left", check(property_scroll_margin_left)),
      ("property_scroll-margin-right", check(property_scroll_margin_right)),
      ("property_scroll-margin-top", check(property_scroll_margin_top)),
      ("property_scroll-padding", check(property_scroll_padding)),
      (
        "property_scroll-padding-block",
        check(property_scroll_padding_block),
      ),
      (
        "property_scroll-padding-block-end",
        check(property_scroll_padding_block_end),
      ),
      (
        "property_scroll-padding-block-start",
        check(property_scroll_padding_block_start),
      ),
      (
        "property_scroll-padding-bottom",
        check(property_scroll_padding_bottom),
      ),
      (
        "property_scroll-padding-inline",
        check(property_scroll_padding_inline),
      ),
      (
        "property_scroll-padding-inline-end",
        check(property_scroll_padding_inline_end),
      ),
      (
        "property_scroll-padding-inline-start",
        check(property_scroll_padding_inline_start),
      ),
      ("property_scroll-padding-left", check(property_scroll_padding_left)),
      (
        "property_scroll-padding-right",
        check(property_scroll_padding_right),
      ),
      ("property_scroll-padding-top", check(property_scroll_padding_top)),
      ("property_scroll-snap-align", check(property_scroll_snap_align)),
      (
        "property_scroll-snap-coordinate",
        check(property_scroll_snap_coordinate),
      ),
      (
        "property_scroll-snap-destination",
        check(property_scroll_snap_destination),
      ),
      (
        "property_scroll-snap-points-x",
        check(property_scroll_snap_points_x),
      ),
      (
        "property_scroll-snap-points-y",
        check(property_scroll_snap_points_y),
      ),
      ("property_scroll-snap-stop", check(property_scroll_snap_stop)),
      ("property_scroll-snap-type", check(property_scroll_snap_type)),
      ("property_scroll-snap-type-x", check(property_scroll_snap_type_x)),
      ("property_scroll-snap-type-y", check(property_scroll_snap_type_y)),
      ("property_scrollbar-color", check(property_scrollbar_color)),
      ("property_scrollbar-width", check(property_scrollbar_width)),
      (
        "property_shape-image-threshold",
        check(property_shape_image_threshold),
      ),
      ("property_shape-margin", check(property_shape_margin)),
      ("property_shape-outside", check(property_shape_outside)),
      ("property_tab-size", check(property_tab_size)),
      ("property_table-layout", check(property_table_layout)),
      ("property_text-align", check(property_text_align)),
      ("property_text-align-last", check(property_text_align_last)),
      (
        "property_text-combine-upright",
        check(property_text_combine_upright),
      ),
      ("property_text-decoration", check(property_text_decoration)),
      (
        "property_text-decoration-color",
        check(property_text_decoration_color),
      ),
      (
        "property_text-decoration-line",
        check(property_text_decoration_line),
      ),
      (
        "property_text-decoration-skip",
        check(property_text_decoration_skip),
      ),
      (
        "property_text-decoration-skip-ink",
        check(property_text_decoration_skip_ink),
      ),
      (
        "property_text-decoration-style",
        check(property_text_decoration_style),
      ),
      (
        "property_text-decoration-thickness",
        check(property_text_decoration_thickness),
      ),
      ("property_text-emphasis", check(property_text_emphasis)),
      ("property_text-emphasis-color", check(property_text_emphasis_color)),
      (
        "property_text-emphasis-position",
        check(property_text_emphasis_position),
      ),
      ("property_text-emphasis-style", check(property_text_emphasis_style)),
      ("property_text-indent", check(property_text_indent)),
      ("property_text-justify", check(property_text_justify)),
      ("property_text-orientation", check(property_text_orientation)),
      ("property_text-overflow", check(property_text_overflow)),
      ("property_text-rendering", check(property_text_rendering)),
      ("property_text-shadow", check(property_text_shadow)),
      ("property_text-size-adjust", check(property_text_size_adjust)),
      ("property_text-transform", check(property_text_transform)),
      (
        "property_text-underline-offset",
        check(property_text_underline_offset),
      ),
      (
        "property_text-underline-position",
        check(property_text_underline_position),
      ),
      ("property_top", check(property_top)),
      ("property_touch-action", check(property_touch_action)),
      ("property_transform", check(property_transform)),
      ("property_transform-box", check(property_transform_box)),
      ("property_transform-origin", check(property_transform_origin)),
      ("property_transform-style", check(property_transform_style)),
      ("property_transition", check(property_transition)),
      ("property_transition-delay", check(property_transition_delay)),
      ("property_transition-duration", check(property_transition_duration)),
      ("property_transition-property", check(property_transition_property)),
      (
        "property_transition-timing-function",
        check(property_transition_timing_function),
      ),
      ("property_translate", check(property_translate)),
      ("property_unicode-bidi", check(property_unicode_bidi)),
      ("property_user-select", check(property_user_select)),
      ("property_vertical-align", check(property_vertical_align)),
      ("property_visibility", check(property_visibility)),
      ("property_white-space", check(property_white_space)),
      ("property_widows", check(property_widows)),
      ("property_width", check(property_width)),
      ("property_will-change", check(property_will_change)),
      ("property_word-break", check(property_word_break)),
      ("property_word-spacing", check(property_word_spacing)),
      ("property_word-wrap", check(property_word_wrap)),
      ("property_writing-mode", check(property_writing_mode)),
      ("property_z-index", check(property_z_index)),
      ("property_zoom", check(property_zoom)),
      ("pseudo-class-selector", check(pseudo_class_selector)),
      ("pseudo-element-selector", check(pseudo_element_selector)),
      ("pseudo-page", check(pseudo_page)),
      ("quote", check(quote)),
      ("relative-selector", check(relative_selector)),
      ("relative-selector-list", check(relative_selector_list)),
      ("relative-size", check(relative_size)),
      ("repeat-style", check(repeat_style)),
      ("self-position", check(self_position)),
      ("shadow", check(shadow)),
      ("shadow-t", check(shadow_t)),
      ("shape", check(shape)),
      ("shape-box", check(shape_box)),
      ("shape-radius", check(shape_radius)),
      ("side-or-corner", check(side_or_corner)),
      ("single-animation", check(single_animation)),
      ("single-animation-direction", check(single_animation_direction)),
      ("single-animation-fill-mode", check(single_animation_fill_mode)),
      (
        "single-animation-iteration-count",
        check(single_animation_iteration_count),
      ),
      ("single-animation-play-state", check(single_animation_play_state)),
      ("single-transition", check(single_transition)),
      ("single-transition-property", check(single_transition_property)),
      ("size", check(size)),
      ("step-position", check(step_position)),
      ("step-timing-function", check(step_timing_function)),
      ("subclass-selector", check(subclass_selector)),
      ("supports-condition", check(supports_condition)),
      ("supports-decl", check(supports_decl)),
      ("supports-feature", check(supports_feature)),
      ("supports-in-parens", check(supports_in_parens)),
      ("supports-selector-fn", check(supports_selector_fn)),
      ("symbol", check(symbol)),
      ("target", check(target)),
      ("time-percentage", check(time_percentage)),
      ("timing-function", check(timing_function)),
      ("track-breadth", check(track_breadth)),
      ("track-list", check(track_list)),
      ("track-repeat", check(track_repeat)),
      ("track-size", check(track_size)),
      ("transform-function", check(transform_function)),
      ("transform-list", check(transform_list)),
      ("type-or-unit", check(type_or_unit)),
      ("type-selector", check(type_selector)),
      ("viewport-length", check(viewport_length)),
      ("wq-name", check(wq_name)),
    ]),
  );
