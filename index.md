# Easing and Splines for UI Animations

The UI of a game is one of the the most important parts that can influence the User Experience for our players. It is also an element that appears almost in every part of our game, from the start of the game, while in the middle of gameplay, to its final scene.

That's the main reason why it is a good idea to improve the UX in our game, starting by the UI!

By using Easing Functions and Splines you can easily give life to the movements and animations of your UI.

## What are those _Easing Functions_ and _Splines_?

### About _Easing Functions_:

As redundant as it may sound, _Easing functions_ are _functions_ that let us control the "speed" of a certain movement within a certain time and duration:


![easing_circular_out](https://github.com/IconicGIT/Easing-and-Splines-for-UI-Animations/blob/main/docs/gifs/easing_circular_out.gif)

_Circular Out easing type_


![easing_bounce_out](https://github.com/IconicGIT/Easing-and-Splines-for-UI-Animations/blob/main/docs/gifs/bounce_out.gif)

_Bounce Out easing type_

![easing_back_oyt](https://github.com/IconicGIT/Easing-and-Splines-for-UI-Animations/blob/main/docs/gifs/back_out.gif)

_Back Out easing type_


### Splines

A spline is a line controlled by a what are called <b>control points</b>, and its shape follows their position by interpolating from one point to another using polynomials. 

![spline_example](https://github.com/IconicGIT/Easing-and-Splines-for-UI-Animations/blob/main/docs/images/spline_example.png)

_Spline Example (in red) formed by two other functions (magenta and green)_

There are many advanced mathematics involvesd in making these ([paper explaining](https://people.cs.clemson.edu/~dhouse/courses/405/notes/splines.pdf)), but the results are remarkable!

They are used in science and mathematics, but they are also applicable to entertainment, such as animation, music and videogames!



![car_spline](https://github.com/frgfm/sdcnd-path-planning/blob/master/static/images/result.gif)

![fish_path](https://d3kjluh73b9h9o.cloudfront.net/original/3X/c/d/cd3780e49cf552f069ff91340c7d002d5c472f5c.gif)

## Usage in Videogames

Well, we know what they are, but how are these things used in videogames?

### Splines in Videogames

A we have seen, splines are very useful when it comes to joining points smoothly. This is particularly useful at the time of making paths of any type, as it can imitate a very organic and fluid movement (as the fish shown earlier).

Similarly, we can use its capabilities to make literal paths. As shown in the next [footage](https://www.youtube.com/watch?v=saAQNRSYU9k), by using a spline defined by some points and a preset of a floor tile, we can make a roadway with a low amount of resources!

### Easing Functions

As shown, easing functions serve to control the speed of a movement. This is an easy explanation, but it can extrapolate to many uses!

For example, we can make some very interesting effects to props and characters in both 2D and 3D games:

![](https://github.com/IconicGIT/Easing-and-Splines-for-UI-Animations/blob/main/docs/gifs/gd_easings.gif)

_Geometry Dash_

![](https://blog.roblox.com/wp-content/uploads/2016/12/elastic.gif)
_Roblox_








## Welcome to GitHub Pages

You can use the [editor on GitHub](https://github.com/IconicGIT/Easing-and-Splines-for-UI-Animations/edit/gh-pages/index.md) to maintain and preview the content for your website in Markdown files.

Whenever you commit to this repository, GitHub Pages will run [Jekyll](https://jekyllrb.com/) to rebuild the pages in your site, from the content in your Markdown files.

### Markdown

Markdown is a lightweight and easy-to-use syntax for styling your writing. It includes conventions for

```markdown
Syntax highlighted code block

# Header 1
## Header 2
### Header 3

- Bulleted
- List

1. Numbered
2. List

**Bold** and _Italic_ and `Code` text

[Link](url) and ![Image](src)
```

For more details see [Basic writing and formatting syntax](https://docs.github.com/en/github/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax).

### Jekyll Themes

Your Pages site will use the layout and styles from the Jekyll theme you have selected in your [repository settings](https://github.com/IconicGIT/Easing-and-Splines-for-UI-Animations/settings/pages). The name of this theme is saved in the Jekyll `_config.yml` configuration file.

### Support or Contact

Having trouble with Pages? Check out our [documentation](https://docs.github.com/categories/github-pages-basics/) or [contact support](https://support.github.com/contact) and we’ll help you sort it out.
