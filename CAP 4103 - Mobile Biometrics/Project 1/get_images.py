# Load imports
import os 
import cv2
import concurrent.futures

'''
function get_images() definition
Parameter, image_directory, is the directory 
holding the images
'''

def increase_brightness(img, value=30):
    hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)
    h, s, v = cv2.split(hsv)

    lim = 255 - value
    v[v > lim] = 255
    v[v <= lim] += value

    final_hsv = cv2.merge((h, s, v))
    img = cv2.cvtColor(final_hsv, cv2.COLOR_HSV2BGR)
    return img



def get_images(image_directory):
    def load_image(subfolder):
        print("Loading images in %s" % subfolder)
        if os.path.isdir(os.path.join(image_directory, subfolder)): # only load directories
            subfolder_files = os.listdir(
                    os.path.join(image_directory, subfolder)
                    )
            for file in subfolder_files:
                if file.endswith(extensions): # grab images only
                    # read the image using openCV                    
                    img = cv2.imread(
                            os.path.join(image_directory, subfolder, file)
                            )
                    # resize the image                     
                    width = 200
                    height = 200
                    dim = (width, height)
                    img = cv2.resize(img, dim)
                    # img = increase_brightness(img, value=50)
                    # add the resized image to a list X
                    X.append(img)
                    # add the image's label to a list y
                    y.append(subfolder)

    X = []
    y = []
    extensions = ('jpg','png','gif')
    
    '''
    Each subject has their own folder with their
    images. The following line lists the names
    of the subfolders within image_directory.
    '''
    subfolders = os.listdir(image_directory)
    for subfolder in subfolders:
    # with concurrent.futures.ThreadPoolExecutor() as executor:
        # executor.map(load_image, subfolders)
        print("Loading images in %s" % subfolder)
        if os.path.isdir(os.path.join(image_directory, subfolder)): # only load directories
            subfolder_files = os.listdir(
                    os.path.join(image_directory, subfolder)
                    )
            for file in subfolder_files:
                if file.endswith(extensions): # grab images only
                    # read the image using openCV                    
                    img = cv2.imread(
                            os.path.join(image_directory, subfolder, file)
                            )
                    # resize the image                     
                    width = 200
                    height = 200
                    dim = (width, height)
                    img = cv2.resize(img, dim)
                    # img = increase_brightness(img, value=50)
                    # add the resized image to a list X
                    X.append(img)
                    # add the image's label to a list y
                    y.append(subfolder)
        
    
    print("All images are loaded")     
    # return the images and their labels      
    return X, y
                    
                
            