# greyscale
Implementation of different conversion algorithms using OpenCV.

## Spread
For each pixel, it selects one of the RGB components and assigns it to the other two components of the pixel.

## Average
Calculates the average of the three color components and assigns it to all subpixels.

## Lightness method
Calculates the average between the maximum and minimum color components and assigns it to all subpixels.

## Weighted sum (luminance preserving)
All subpixels get the value obtained by: 0.2126R + 0.7152G + 0.0722B
