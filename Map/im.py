if __name__ == "__main__":
	from sys import argv, stdin
	from PIL import Image

	im = Image.open(argv[1])
	for y in range(0, im.size[1]):
		for x in range(0, im.size[0]):
			pix = im.getpixel((x, y))
			##print(pix)
			if pix[0] < 150 and pix[1] < 150 and pix[2] < 150:
				print("{} ".format(pix[0] / 10)),
			else:
				print("{} ".format(0)),
		print('\n'),
